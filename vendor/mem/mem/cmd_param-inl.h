/*
    Copyright 2018 Brick

    Permission is hereby granted, free of charge, to any person obtaining a copy of this software
    and associated documentation files (the "Software"), to deal in the Software without restriction,
    including without limitation the rights to use, copy, modify, merge, publish, distribute,
    sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is
    furnished to do so, subject to the following conditions:

    The above copyright notice and this permission notice shall be included in all copies or
    substantial portions of the Software.

    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING
    BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
    NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
    DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
    OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

#if defined(MEM_CMD_PARAM_INL_BRICK_H)
#    error mem/cmd_param-inl.h should only be included once
#endif // MEM_CMD_PARAM_INL_BRICK_H

#define MEM_CMD_PARAM_INL_BRICK_H

#if !defined(CMD_ALLOC_BUFFER_CAPACITY)
#    define CMD_ALLOC_BUFFER_CAPACITY 0x1000
#endif

#if !defined(CMD_HASH_TABLE_BUCKETS)
#    define CMD_HASH_TABLE_BUCKETS 128
#endif

#include "cmd_param.h"

#include <cctype>
#include <cstring>

namespace mem
{
    static inline char cmd_tolower(char c)
    {
        if (c >= 'A' && c <= 'Z')
            c += 'A' - 'a';

        return c;
    }

    static inline bool cmd_is_option(const char* arg)
    {
        return (arg[0] == '-') && !(arg[1] >= '0' && arg[1] <= '9');
    }

    static std::uint32_t cmd_strhash(const char* str, std::size_t len)
    {
        std::uint32_t hash = 0;

        for (std::size_t i = 0; i != len; ++i)
        {
            hash += cmd_tolower(str[i]);
            hash += hash << 10;
            hash ^= hash >> 6;
        }

        hash += hash << 3;
        hash ^= hash >> 11;
        hash += hash << 15;

        return hash;
    }

    static char cmd_alloc_buffer[CMD_ALLOC_BUFFER_CAPACITY];
    static std::size_t cmd_alloc_buffer_len {0};

    static char* cmd_strdup(const char* value, std::size_t len)
    {
        if (cmd_alloc_buffer_len + len >= CMD_ALLOC_BUFFER_CAPACITY)
            return nullptr;

        char* result = &cmd_alloc_buffer[cmd_alloc_buffer_len];
        std::memcpy(result, value, len);
        result[len] = '\0';

        cmd_alloc_buffer_len += len + 1;
        return result;
    }

    static int cmd_stricmp(const char* lhs, const char* rhs)
    {
        while (true)
        {
            unsigned char a = static_cast<unsigned char>(cmd_tolower(*lhs++));
            unsigned char b = static_cast<unsigned char>(cmd_tolower(*rhs++));

            if (int diff = static_cast<int>(a) - static_cast<int>(b); diff != 0 || a == 0)
                return diff;
        }

        return 0;
    }

    static bool cmd_strequal(const char* lhs, const char* rhs, std::size_t length)
    {
        for (std::size_t i = 0; i < length; ++i)
        {
            if (cmd_tolower(lhs[i]) != cmd_tolower(rhs[i]))
                return false;
        }

        return lhs[length] == '\0';
    }

    void cmd_param::init(const char* const* argv)
    {
        int argc = 0;

        while (argv[argc])
            ++argc;

        init(argc, argv);
    }

    void cmd_param::init(int argc, const char* const* argv)
    {
        bool done_positionals = false;

        for (int i = 1; i < argc; ++i)
        {
            const char* arg = argv[i];

            if (cmd_is_option(arg))
            {
                done_positionals = true;

                while (arg[0] == '-')
                    ++arg;

                const char* value = arg;

                while (*value && *value != '=')
                    ++value;

                std::size_t arg_len = value - arg;

                if (*value == '=')
                    ++value;
                else if (i + 1 < argc && !cmd_is_option(argv[i + 1]))
                    value = argv[i + 1];
                else
                    value = "1";

                set(arg, value, arg_len);
            }
            else if (!done_positionals)
            {
                char pos[16];
                std::size_t pos_len = static_cast<std::size_t>(std::snprintf(pos, 16, "%i", i));
                set(pos, arg, pos_len);
            }
        }
    }

    static cmd_param* cmd_hash_table[CMD_HASH_TABLE_BUCKETS];

    MEM_NOINLINE cmd_param::cmd_param(const char* name, const char* description, const char* value) noexcept
        : name_(name)
        , description_(description)
        , value_(value)
        , default_value_(value)
    {
        std::size_t length = std::strlen(name_);
        hash_ = cmd_strhash(name_, length);

        cmd_param** bucket = &cmd_hash_table[hash_ % CMD_HASH_TABLE_BUCKETS];

        for (cmd_param* i = *bucket; i; i = i->next_)
        {
            if (i->hash_ == hash_ && cmd_strequal(i->name_, name_, length))
                std::abort();
        }

        next_ = *bucket;
        *bucket = this;
    }

    MEM_NOINLINE cmd_param::~cmd_param()
    {
        for (cmd_param** i = &cmd_hash_table[hash_ % CMD_HASH_TABLE_BUCKETS]; *i; i = &(*i)->next_)
        {
            if (*i == this)
            {
                *i = (*i)->next_;
                break;
            }
        }
    }

    void cmd_param::reset()
    {
        for (cmd_param* i : cmd_hash_table)
        {
            for (; i; i = i->next_)
                i->value_ = i->default_value_;
        }

        cmd_alloc_buffer_len = 0;
    }

    cmd_param* cmd_param::lookup(const char* name, std::size_t length)
    {
        std::uint32_t hash = cmd_strhash(name, length);

        for (cmd_param* i = cmd_hash_table[hash % CMD_HASH_TABLE_BUCKETS]; i; i = i->next_)
        {
            if (i->hash_ == hash && cmd_strequal(i->name_, name, length))
                return i;
        }

        return nullptr;
    }

    void cmd_param::set(const char* key, const char* value, std::size_t key_len, std::size_t value_len)
    {
        if (key_len == SIZE_MAX)
            key_len = std::strlen(key);

        if (value_len == SIZE_MAX)
            value_len = value ? std::strlen(value) : 0;

        if (cmd_param* cmd = lookup(key, key_len))
        {
            cmd->value_ = value ? cmd_strdup(value, value_len) : cmd->default_value_;
        }
        else if (key_len > 2 && cmd_strequal("no", key, 2))
        {
            cmd = lookup(key + 2, key_len - 2);

            if (cmd)
            {
                cmd->value_ = (value && !std::strncmp(value, "0", value_len)) ? "1" : "0";
            }
        }
    }

    std::size_t cmd_param::collect(cmd_param** values, std::size_t capacity)
    {
        std::size_t count = 0;

        for (cmd_param* i : cmd_hash_table)
        {
            for (; i; i = i->next_)
            {
                if (values)
                {
                    if (count < capacity)
                        values[count++] = i;
                    else
                        return 0;
                }
            }
        }

        if (values)
        {
            std::sort(values, values + count,
                [](cmd_param* lhs, cmd_param* rhs) { return cmd_stricmp(lhs->name(), rhs->name()) < 0; });
        }

        return count;
    }
} // namespace mem
