# How to build

## Visual Studio 2022

The Open1560 code is build and developed using Visual Studio 2022. The community edition can be downloaded [here](https://visualstudio.microsoft.com/vs/community/). Make sure to install the C++ tools with it.


## Fork and clone the repo


## Prepare script

After having done that, shift+right click on the directory and select "Open PowerShell window here". Then run the following command with after replacing the location of the Midtown Madness in it:

```
tools/premake5.exe --MM1_GAME_DIRECTORY=c:/location/of/mm1/installation
```

Make sure to use `/`s and not `\`s in the path.

## Get started

Now the code can be openened by opening the newly created `build/Open1560.sln` project file for Visual Studio. If all the previous steps were done correctly, clicking `Start Debugging` at the top of the screen in Visual Studio should build and run Open1560. Feel free to play around with the code and make changes.
