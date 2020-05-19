/*
    Open1560 - An Open Source Re-Implementation of Midtown Madness 1 Beta
    Copyright (C) 2020 Brick

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program. If not, see <http://www.gnu.org/licenses/>.
*/

define_dummy_symbol(data7_callback);

#include "callback.h"

#define TYPE_CFA 1
#define TYPE_CFA1 2
#define TYPE_CFA2 3

#define TYPE_MFA 1
#define TYPE_MFA1 2
#define TYPE_MFA2 3
#define TYPE_MFA3 4

Callback::Callback(Static0 func) noexcept
    : type_(TYPE_CFA)
{
    export_hook(0x5793D0);

    func_.static0 = func;
}

Callback::Callback(Static1 func, void* param) noexcept
    : type_(TYPE_CFA1)
    , first_param_(param)
{
    export_hook(0x5793F0);

    func_.static1 = func;
}

Callback::Callback(Static2 func, void* param) noexcept
    : type_(TYPE_CFA2)
    , first_param_(param)
{
    export_hook(0x579420);

    func_.static2 = func;
}

Callback::Callback(Member0 func, Base* param) noexcept
    : type_(TYPE_MFA)
    , this_param_(param)
{
    export_hook(0x5792D0);

    func_.member0 = func;

    if (!param)
        Quitf("Can't have callback to member function with nil 'this'");
}

Callback::Callback(Member1 func, Base* param1, void* param2) noexcept
    : type_(TYPE_MFA1)
    , this_param_(param1)
    , first_param_(param2)
{
    export_hook(0x579310);

    func_.member1 = func;

    if (!param1)
        Quitf("Can't have callback to member function with nil 'this'");
}

Callback::Callback(Member2 func, Base* param1, void* param2) noexcept
    : type_(TYPE_MFA2)
    , this_param_(param1)
    , first_param_(param2)
{
    export_hook(0x579350);

    func_.member2 = func;

    if (!param1)
        Quitf("Can't have callback to member function with nil 'this'");
}

Callback::Callback(Member2 func, Base* param1, void* param2, void* param3) noexcept
    : type_(TYPE_MFA3)
    , this_param_(param1)
    , first_param_(param2)
    , second_param_(param3)
{
    export_hook(0x579390);

    func_.member2 = func;

    if (!param1)
        Quitf("Can't have callback to member function with nil 'this'");
}

void Callback::Call(void* param)
{
    export_hook(0x579450);

    if (type_)
    {
        if (this_param_)
        {
            switch (type_)
            {
                case TYPE_MFA: return (this_param_->*func_.member0)();
                case TYPE_MFA1: return (this_param_->*func_.member1)(first_param_);
                case TYPE_MFA2: return (this_param_->*func_.member2)(first_param_, param);
                case TYPE_MFA3: return (this_param_->*func_.member2)(first_param_, second_param_);

                default: Quitf("Invalid Callback");
            }
        }
        else
        {
            switch (type_)
            {
                case TYPE_CFA: return func_.static0();
                case TYPE_CFA1: return func_.static1(first_param_);
                case TYPE_CFA2: return func_.static2(first_param_, param);

                default: Quitf("Invalid Callback");
            }
        }
    }
}
