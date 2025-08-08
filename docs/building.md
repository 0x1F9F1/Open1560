# How to build

To be able to make changes to the Open1560 code a development environment is required. This page will explain how to set this up.

## Visual Studio 2022

The Open1560 code is build and developed using Visual Studio 2022. The community edition can be downloaded [here](https://visualstudio.microsoft.com/vs/community/). Make sure to select `Desktop Development with C++" during the installation.

## Git clone

Use [git](https://git-scm.com/) bash to clone the repo with the following command:
```
git clone https://github.com/0x1F9F1/Open1560.git
```

Replace `0x1F9F1` with your own GitHub username if you created a fork already.

This will create the Open1560 directory.

## Prepare script

After having done that, shift+right click on the directory Open1560 directory and select "Open PowerShell window here". Then run the following command with after replacing the location of the Midtown Madness in it:

```
tools/premake5.exe vs2022 --MM1_GAME_DIRECTORY=c:/location/of/mm1/installation
```

Make sure to use `/`s and not `\`s in the Midtown Madness path.

This will create the Visual Studio project files which will be used in the next step.

## Get started

Now the code can be openened by double clicking the newly created `build/Open1560.sln` project file for Visual Studio. If all the previous steps were done correctly, clicking `Start Debugging` at the top of the screen in Visual Studio should build and run Open1560. Feel free to play around with the code and make changes.

For more in-depth development information, see [methodology](./methodology.md).