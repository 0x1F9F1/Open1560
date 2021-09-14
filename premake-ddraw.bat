@echo off

"tools/premake5.exe" vs2019 --ARTS_DISABLE_OPENGL

IF %ERRORLEVEL% NEQ 0 (
    pause
)