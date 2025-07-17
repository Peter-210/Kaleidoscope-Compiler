@echo off

if "%1"=="" goto main
if "%1"=="main" goto main
goto error

:error
echo Invalid argument. Use either "main" or "debug"
goto end

:main
echo Running cmake --workflow main
cmake --workflow main
goto end

:end
exit