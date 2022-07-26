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

#ifndef MEM_STATIC_FUNCTION_BRICK_H
#define MEM_STATIC_FUNCTION_BRICK_H

#include "defines.h"

namespace mem
{
    class static_function
    {
    public:
        using callback_t = void (*)();

        constexpr static_function() noexcept = default;
        static_function(static_function*& parent, callback_t callback) noexcept;

        static_function(const static_function&) = delete;
        static_function(static_function&&) = delete;

        static std::size_t exec(static_function*& root, bool clear);

    private:
        callback_t callback_ {nullptr};
        static_function* next_ {nullptr};
    };

    MEM_STRONG_INLINE static_function::static_function(static_function*& parent, callback_t callback) noexcept
        : callback_(callback)
        , next_(parent)
    {
        parent = this;
    }

    MEM_STRONG_INLINE std::size_t static_function::exec(static_function*& root, bool clear)
    {
        std::size_t total = 0;

        static_function* i = root;

        if (clear)
            root = nullptr;

        while (i)
        {
            if (i->callback_)
            {
                i->callback_();

                if (clear)
                    i->callback_ = nullptr;

                ++total;
            }

            static_function* j = i->next_;

            if (clear)
                i->next_ = nullptr;

            i = j;
        }

        return total;
    }
} // namespace mem

#endif // MEM_STATIC_FUNCTION_BRICK_H
