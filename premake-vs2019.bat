@echo off

"tools/premake5.exe" vs2019

IF %ERRORLEVEL% NEQ 0 (
    pause
)