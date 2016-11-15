@echo off
setlocal
path C:\Program Files (x86)\Dev-Cpp\MinGW64\bin\;C:\Program Files (x86)\Dev-Cpp\MinGW64\libexec\gcc\x86_64-w64-mingw32\4.8.1\;%path%
for /f "tokens=1,* delims= " %%a in ("%*") do set ALL_BUT_FIRST=%%b
g++ -o %1  %ALL_BUT_FIRST%
endlocal
echo on