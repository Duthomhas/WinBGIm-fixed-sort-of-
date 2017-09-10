@echo off
:: Written 2017 Michael Thomas Greer
:: Released to the Public Domain
setlocal enableextensions

if "%1" == ""       goto :HELP
if "%1" == "/?"     goto :HELP
if "%1" == "--help" goto :HELP
goto :OK

:HELP
echo usage:
echo   %~n0 FILE ...
echo.
echo Compiles your WinBGIm program. The first argument must be the name of the
echo file containing your main() function. Unless overridden by specifying a
echo preferred executable filename using -o FILENAME, it will also be the name 
echo of your final executable. For example:
echo.
echo   %~n0 pong.cpp data.cpp options.cpp
echo.
echo produces an executable named "pong.exe".
echo.
echo You can also specify other standard compile options on the command line,
echo such as additional libraries you wish to link with.
echo.
goto :EOF

:OK
g++ -std=c++11 -Wall -pedantic -m32 -mwindows -s -I. -L. -o %~n1.exe %* -lbgi -lgdi32 -lcomdlg32 -luuid -loleaut32 -lole32
