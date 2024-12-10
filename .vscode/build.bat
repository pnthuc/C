@echo off
dir /S /B *.cpp > "%CD%\files.txt"

(for /F "delims=" %%i in (files.txt) do (
    set "line=%%i"
    setlocal enabledelayedexpansion
    set "line=!line:\=/!"
    echo !line!
    endlocal
)) > temp.txt

move /Y temp.txt files.txt
g++ -g @files.txt -o main.exe
del files.txt

@REM cd %CD% && COPY.exe

@REM "%CD%\main.exe"

@REM 