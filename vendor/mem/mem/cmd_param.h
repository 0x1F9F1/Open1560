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

#ifndef MEM_CMD_PARAM_BRICK_H
#define MEM_CMD_PARAM_BRICK_H

#include "defines.h"

#include <cstdlib>

namespace mem
{
    class cmd_param
    {
    public:
        cmd_param(const char* name, const char* description = nullptr, const char* value = nullptr) noexcept;
        ~cmd_param();

        cmd_param(const cmd_param&) = delete;
        cmd_param(cmd_param&&) = delete;

        const char* name() const;
        const char* description() const;

        const char* value() const;
        const char* default_value() const;
        bool is_default() const;

        template <typename T>
        T get() const;

        template <typename T>
        bool get(T& out) const;

        template <typename T>
        T get_or(T value) const;

        operator bool() const;

        static void init(const char* const* argv);
        static void init(int argc, const char* const* argv);
        static void reset();

        static std::size_t collect(cmd_param** values, std::size_t capacity);

    private:
        const char* name_ {nullptr};
        const char* description_ {nullptr};

        const char* value_ {nullptr};
        const char* default_value_ {nullptr};

        std::uint32_t hash_ {0};
        cmd_param* next_ {nullptr};

        void link();
        void unlink();

        static cmd_param* lookup(const char* name, std::size_t length);
    };

    template <typename T>
    bool parse_cmd(const char* value, T& out);

    MEM_STRONG_INLINE const char* cmd_param::name() const
    {
        return name_;
    }

    MEM_STRONG_INLINE const char* cmd_param::description() const
    {
        return description_;
    }

    MEM_STRONG_INLINE const char* cmd_param::value() const
    {
        return value_;
    }

    MEM_STRONG_INLINE const char* cmd_param::default_value() const
    {
        return default_value_;
    }

    MEM_STRONG_INLINE bool cmd_param::is_default() const
    {
        return value_ == default_value_;
    }

    template <>
    MEM_STRONG_INLINE bool parse_cmd<const char*>(const char* value, const char*& out)
    {
        out = value;

        return true;
    }

    template <>
    MEM_STRONG_INLINE bool parse_cmd<bool>(const char* value, bool& out)
    {
        if (!std::strcmp(value, "false") || !std::strcmp(value, "0"))
        {
            out = false;
        }
        else
        {
            out = true;
        }

        return true;
    }

    template <>
    MEM_STRONG_INLINE bool parse_cmd<short>(const char* value, short& out)
    {
        out = static_cast<short>(std::strtol(value, nullptr, 0));

        return true;
    }

    template <>
    MEM_STRONG_INLINE bool parse_cmd<unsigned short>(const char* value, unsigned short& out)
    {
        out = static_cast<unsigned short>(std::strtoul(value, nullptr, 0));

        return true;
    }

    template <>
    MEM_STRONG_INLINE bool parse_cmd<int>(const char* value, int& out)
    {
        out = static_cast<int>(std::strtol(value, nullptr, 0));

        return true;
    }

    template <>
    MEM_STRONG_INLINE bool parse_cmd<unsigned int>(const char* value, unsigned int& out)
    {
        out = static_cast<unsigned int>(std::strtoul(value, nullptr, 0));

        return true;
    }

    template <>
    MEM_STRONG_INLINE bool parse_cmd<long>(const char* value, long& out)
    {
        out = std::strtol(value, nullptr, 0);

        return true;
    }

    template <>
    MEM_STRONG_INLINE bool parse_cmd<unsigned long>(const char* value, unsigned long& out)
    {
        out = std::strtoul(value, nullptr, 0);

        return true;
    }

    template <>
    MEM_STRONG_INLINE bool parse_cmd<long long>(const char* value, long long& out)
    {
        out = std::strtoll(value, nullptr, 0);

        return true;
    }

    template <>
    MEM_STRONG_INLINE bool parse_cmd<unsigned long long>(const char* value, unsigned long long& out)
    {
        out = std::strtoull(value, nullptr, 0);

        return true;
    }

    template <>
    MEM_STRONG_INLINE bool parse_cmd<float>(const char* value, float& out)
    {
        out = std::strtof(value, nullptr);

        return true;
    }

    template <>
    MEM_STRONG_INLINE bool parse_cmd<double>(const char* value, double& out)
    {
        out = std::strtod(value, nullptr);

        return true;
    }

    template <>
    MEM_STRONG_INLINE bool parse_cmd<long double>(const char* value, long double& out)
    {
        out = std::strtold(value, nullptr);

        return true;
    }

    template <typename T>
    MEM_STRONG_INLINE T cmd_param::get() const
    {
        return get_or<T>({});
    }

    template <typename T>
    MEM_STRONG_INLINE bool cmd_param::get(T& out) const
    {
        if (value_)
        {
            return parse_cmd(value_, out);
        }

        return false;
    }

    template <typename T>
    MEM_STRONG_INLINE T cmd_param::get_or(T value) const
    {
        if (value_)
        {
            parse_cmd(value_, value);
        }

        return value;
    }

    MEM_STRONG_INLINE cmd_param::operator bool() const
    {
        return get<bool>();
    }
} // namespace mem

#endif // MEM_CMD_PARAM_BRICK_H
