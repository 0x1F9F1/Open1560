@echo off

"tools/premake5.exe" vs2022

IF %ERRORLEVEL% NEQ 0 (
    pause
)