@echo off
setlocal
cd /d "%~dp0"
set "INCLUDE=C:\Pack RadASM\fasm\INCLUDE"
"C:\Pack RadASM\fasm\FASM.EXE" main.asm calculadora.exe
exit /b %errorlevel%