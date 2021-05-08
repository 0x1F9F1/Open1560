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

define_dummy_symbol(stream_problems);

#include "problems.h"

static constexpr usize MAX_PROBLEMS = 4096;

#include "data7/str.h"
#include "hfsystem.h"
#include "stream.h"

struct problem_t
{
public:
    ConstString Message;
    ConstString Target;
    ConstString Location;
    i32 Count {1};
};

check_size(problem_t, 0x10);

// 0x561050 | ?cmpProblem@@YAHPBX0@Z
ARTS_EXPORT /*static*/ i32 cmpProblem(void const* a, void const* b)
{
    const problem_t& lhs = **static_cast<problem_t* const*>(a);
    const problem_t& rhs = **static_cast<problem_t* const*>(b);

    i32 result = std::strcmp(lhs.Message.get(), rhs.Message.get());

    if (result == 0)
        result = std::strcmp(lhs.Target.get(), rhs.Target.get());

    if (result == 0)
        result = std::strcmp(lhs.Location.get(), rhs.Location.get());

    return result;
}

static problem_t* Problems[MAX_PROBLEMS];
static i32 NumProblems = 0;

void DumpProblems()
{
    if (DevelopmentMode && !LogOpenOn)
    {
        std::qsort(Problems, NumProblems, sizeof(*Problems), cmpProblem);

        char output_path[1024];
        arts_sprintf(output_path, "%s/problems.txt", ProjPath);

        if (Ptr<Stream> output {arts_fopen(output_path, "w")})
        {
            output->Printf("Total Problems: %i\n", NumProblems);

            for (i32 i = 0; i < NumProblems;)
            {
                i32 j = i + 1;

                for (; j < NumProblems; ++j)
                {
                    if (Problems[i]->Message != Problems[j]->Message)
                        break;
                }

                output->Printf("MESSAGE: %s\n", Problems[i]->Message.get());

                while (i < j)
                {
                    i32 k = i + 1;

                    for (; k < j; ++k)
                    {
                        if (Problems[i]->Target != Problems[k]->Target)
                            break;
                    }

                    if ((i + 1 != k) || (Problems[i]->Location != ""))
                    {
                        output->Printf("    '%s' at locations:\n", Problems[i]->Target.get());

                        for (; i < k; ++i)
                        {
                            if (i32 count = Problems[i]->Count; count > 1)
                                output->Printf("        '%s' (%d times)\n", Problems[i]->Location.get(), count);
                            else
                                output->Printf("        '%s'\n", Problems[i]->Location.get());
                        }
                    }
                    else
                    {
                        output->Printf("    '%s'\n", Problems[i]->Target.get());

                        ++i;
                    }
                }
            }
        }
    }

    InitProblems();
}

void InitProblems()
{
    while (NumProblems)
        delete Problems[--NumProblems];
}

void RegisterProblem(const char* message, const char* target, const char* location)
{
    if (NumProblems == MAX_PROBLEMS)
        return;

    message = message ? message : "";
    target = target ? target : "";
    location = location ? location : "";

    for (i32 i = 0; i < NumProblems; ++i)
    {
        problem_t& problem = *Problems[i];

        if ((message == problem.Message) && (target == problem.Target) && (location == problem.Location))
        {
            ++problem.Count;

            return;
        }
    }

    Problems[NumProblems++] = new problem_t {ConstString(message), ConstString(target), ConstString(location), 1};

    if (NumProblems == MAX_PROBLEMS - 1)
        RegisterProblem("Out of space in problem database", nullptr, "Problem Database");
}
