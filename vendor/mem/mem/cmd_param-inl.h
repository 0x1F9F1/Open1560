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

#include "cmd_param.h"

#include <cctype>
#include <cstring>

namespace mem
{
    cmd_param* cmd_param::ROOT {nullptr};

    static inline bool cmd_is_digit(char c)
    {
        return (c >= '0') && (c <= '9');
    }

    static inline int cmd_to_lower(char c)
    {
        int v = static_cast<unsigned char>(c);

        if ((v >= 'A') && (v <= 'Z'))
        {
            v += ('a' - 'A');
        }

        return v;
    }

    static inline bool cmd_is_option(const char* arg)
    {
        return (arg[0] == '-') && !cmd_is_digit(arg[1]);
    }

    static char* cmd_unquote(char* arg)
    {
        if (arg[0] == '"')
        {
            ++arg;

            char* last = arg + std::strlen(arg) - 1;

            if (last[0] == '"')
                last[0] = '\0';
        }

        return arg;
    }

    static int cmd_strcmp(const char* lhs, const char* rhs)
    {
        int a, b;

        do
        {
            a = cmd_to_lower(*lhs++);
            b = cmd_to_lower(*rhs++);
        } while (a && a == b);

        if (a == '\0' && b == '=')
            b = '\0';

        return a - b;
    }

    static char* cmd_strdup(const char* value)
    {
        char* result = nullptr;

        if (value)
        {
            size_t length = std::strlen(value) + 1;

            result = new char[length];

            if (result)
            {
                std::memcpy(result, value, length);
            }
        }

        return result;
    }

    void cmd_param::init(const char* const* argv)
    {
        int argc = 0;

        while (argv[argc])
        {
            ++argc;
        }

        init(argc, argv);
    }

    void cmd_param::init(int argc, const char* const* argv)
    {
        if (argc < 2)
            return;

        char** args = new char*[argc];

        args[0] = nullptr;

        for (int i = 1; i < argc; ++i)
            args[i] = cmd_strdup(argv[i]);

        bool done_positionals = false;

        for (int i = 1; i < argc; ++i)
        {
            char* arg = args[i];

            if (cmd_is_option(arg))
            {
                while (arg[0] == '-')
                    ++arg;

                done_positionals = true;

                bool used = false;

                for (cmd_param* j = ROOT; j; j = j->next_)
                {
                    if (j->name_)
                    {
                        if (!cmd_strcmp(j->name_, arg))
                        {
                            const char* value = "";

                            if (char* val = std::strchr(arg, '='))
                            {
                                value = cmd_unquote(val + 1);
                            }
                            else if (i + 1 < argc)
                            {
                                char* next_arg = args[i + 1];

                                if (!cmd_is_option(next_arg))
                                {
                                    value = cmd_unquote(next_arg);
                                }
                            }

                            j->value_ = value;

                            used = true;
                        }
                    }
                }

                if (!used)
                {
                    for (cmd_param* j = ROOT; j; j = j->next_)
                    {
                        if (j->name_)
                        { // clang-format off
                            if ((!std::strncmp(arg,      "no", 2) && !cmd_strcmp(j->name_, arg + 2)) ||
                                (!std::strncmp(j->name_, "no", 2) && !cmd_strcmp(j->name_ + 2, arg)))
                            {
                                j->value_ = "false";

                                used = true;
                            }
                        } // clang-format on
                    }
                }
            }
            else if (!done_positionals)
            {
                for (cmd_param* j = ROOT; j; j = j->next_)
                {
                    if (j->pos_ == i)
                    {
                        const char* value = cmd_unquote(arg);

                        j->value_ = value;
                    }
                }
            }
        }

        delete[] args;
    }
} // namespace mem
