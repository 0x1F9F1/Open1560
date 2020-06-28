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

define_dummy_symbol(data7_args);

#include "args.h"

static char EmptyArg[] {""};

asArg::asArg(char flag, const char* usage)
    : Flag(flag)
    , Usage(arts_strdup(usage))
{
    for (usize i = 0; i < 5; ++i)
    {
        iValues[i] = 0;
        fValues[i] = 0.0f;
        sValues[i] = EmptyArg;
    }
}

void asArg::Print(const char* name)
{
    Displayf("%s: Found: %d Flag: %c Msg: (%s)", name ? name : "ARG", Found, Flag, Usage);

    Displayf("\tContents:");

    for (size_t i = 0; i < 5; ++i)
        Displayf("\t\t[%d] IVal: %d FVal: %f SVal: (%s)", i, iValues[i], fValues[i], sValues[i]);
}

ArgSet::~ArgSet()
{
    // NOTE: Leaks `Path`

    for (asArg* arg : Args)
    {
        // NOTE: Leaks asArg::Usage
        // NOTE: Leaks asArg::sValues

        if (arg)
            delete arg;
    }
}

void ArgSet::ParseArgs(i32 argc, const char** argv)
{
    if (!argv || Path != nullptr)
        return;

    Path = arts_strdup(argv[0]);

    i32 index = 1;

    while (index < argc)
    {
        if (argv[index][0] == '-')
            break;

        if (++index > 5)
            break;
    }

    while (index < argc)
    {
        const char* arg = argv[index];

        if (arg[0] != '-')
        {
            Errorf("ARGSET::ParseArgs()- unknown flag format: %c (arg %d)", arg[0], index);
            break;
        }

        if (arg[1] == '\0')
        {
            Errorf("ARGSET::ParseArgs()- no flag specified (arg %d)", index);
            break;
        }

        if (arg[1] >= '0' && arg[1] <= '9')
        {
            Errorf("ARGSET::ParseArgs()- can't have digit %c as flag (arg %d)", arg[1], index);
            break;
        }

        if (std::strcmp(arg, "-help") == 0)
        {
            break;
        }

        asArg* value = Args[arg[1]];

        if (value == nullptr)
        {
            value = new asArg(arg[1], nullptr);

            // NOTE: Leaks memory if arg[2] != '\0'
            if (arg[2] == '\0')
                Args[value->Flag] = value;
        }

        ++index;

        i32 count = 0;

        while (index < argc)
        {
            arg = argv[index];

            if (arg[0] == '-' && (arg[1] < '0' || arg[1] > '9'))
                break;

            // NOTE: Overwrites previous values if argument occurs more than once
            value->iValues[count] = static_cast<i32>(std::atoi(arg));
            value->fValues[count] = static_cast<f32>(std::atof(arg));

            // NOTE: Leaks sValues if overwritten
            value->sValues[count] = arts_strdup(arg);

            ++index;

            if (++count >= 5)
                break;
        }

        value->Found = true;
    }

    if (index < argc)
    {
        Usage();

        std::exit(0);
    }
}

void ArgSet::Print(const char* title)
{
    Displayf("%s:", title ? title : "ARGSET");

    for (asArg* arg : Args)
    {
        if (arg)
            arg->Print("\n");
    }
}

void ArgSet::Usage()
{
    Displayf("Usage:\t%s", Path);
    Displayf("\n");

    for (asArg* arg : Args)
    {
        if (arg)
        {
            if (arg->Flag != ' ')
            {
                Displayf("\t[-%c]\t%s", arg->Flag, arg->Usage);
            }
        }
    }

    Displayf("\t[-help]\tdisplays usage");
}
