@echo off
echo ===============================
echo Building Swords and Magic (RELEASE)
echo ===============================

REM Create output folder if needed
if not exist "bin" mkdir "bin"

REM Compile with optimizations and no console
g++ -O2 -DNDEBUG -mwindows -o "bin/Swords & Magic.exe" main.cpp ^
    "src/Sources/Game.cpp" ^
    "src/Sources/Screen.cpp" ^
    "src/Sources/HomeScreen.cpp" ^
    "src/Sources/HowToPlayScreen.cpp" ^
    "src/Sources/CreditsScreen.cpp" ^
    "src/Sources/AboutScreen.cpp" ^
    "src/Sources/GameOverScreen.cpp" ^
    "src/Sources/Entity.cpp" ^
    "src/Sources/Player.cpp" ^
    "src/Sources/Enemy.cpp" ^
    "src/Sources/FlyingDemon.cpp" ^
    "src/Sources/Skeleton.cpp" ^
    "src/Sources/GameRoom.cpp" ^
    "src/Sources/Score.cpp" ^
    resource.o -I"include" -L"lib" ^
    -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

if errorlevel 1 (
    echo Build failed. Please check for compile errors.
    pause
    exit /b
)

REM Locate the g++ bin directory to copy DLLs
set "BIN_DIR="
for /f "usebackq delims=" %%G in (`where g++ 2^>nul`) do (
    set "GPP_PATH=%%G"
    goto :found_gpp
)
:found_gpp
if defined GPP_PATH (
    for %%D in ("%GPP_PATH%") do set "BIN_DIR=%%~dpD"
) else (
    set "BIN_DIR=C:\msys64\mingw64\bin"
)

REM Trim trailing backslash
if "%BIN_DIR:~-1%"=="\" set "BIN_DIR=%BIN_DIR:~0,-1%"

REM Copy MinGW runtime DLLs
for %%F in (libstdc++-6.dll libwinpthread-1.dll libgcc_s_seh-1.dll libgcc_s_sjlj-1.dll libgcc_s_dw2-1.dll) do (
    if exist "%BIN_DIR%\%%F" copy /Y "%BIN_DIR%\%%F" "bin\" >nul
)

REM Copy SFML DLLs (version-agnostic)
for %%F in (sfml-graphics-3.dll sfml-window-3.dll sfml-system-3.dll sfml-audio-3.dll ^
            libsfml-graphics-3.dll libsfml-window-3.dll libsfml-system-3.dll libsfml-audio-3.dll ^
            sfml-graphics-2.dll sfml-window-2.dll sfml-system-2.dll sfml-audio-2.dll) do (
    if exist "%BIN_DIR%\%%F" copy /Y "%BIN_DIR%\%%F" "bin\" >nul
)

echo ===============================
echo Build complete! Release ready in /bin
echo ===============================
pause
