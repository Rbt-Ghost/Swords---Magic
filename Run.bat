g++ -o "bin/Swords & Magic.exe" main.cpp ^
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
    resource.o -I"include" -L"lib" -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

REM create output folder if needed
if not exist "bin" mkdir "bin"

REM Try to locate the g++ used to build (prefer that toolchain's bin)
set "BIN_DIR="
for /f "usebackq delims=" %%G in (`where g++ 2^>nul`) do (
    rem %%G is full path to g++.exe; get its directory
    set "GPP_PATH=%%G"
    goto :found_gpp
)
:found_gpp
if defined GPP_PATH (
    for %%D in ("%GPP_PATH%") do set "BIN_DIR=%%~dpD"
) else (
    REM fallback to common MSYS2 path; change if your MSYS2 is elsewhere
    set "BIN_DIR=C:\msys64\mingw64\bin\"
)

REM Trim trailing backslash if any
if defined BIN_DIR (
    if "%BIN_DIR:~-1%"=="\" set "BIN_DIR=%BIN_DIR:~0,-1%"
)

REM Copy common MinGW runtime DLLs from the toolchain used for build
if exist "%BIN_DIR%\libstdc++-6.dll" copy /Y "%BIN_DIR%\libstdc++-6.dll" "bin\"
if exist "%BIN_DIR%\libwinpthread-1.dll" copy /Y "%BIN_DIR%\libwinpthread-1.dll" "bin\"

REM libgcc has different names depending on exception model - try common variants
if exist "%BIN_DIR%\libgcc_s_seh-1.dll" copy /Y "%BIN_DIR%\libgcc_s_seh-1.dll" "bin\"
if exist "%BIN_DIR%\libgcc_s_sjlj-1.dll" copy /Y "%BIN_DIR%\libgcc_s_sjlj-1.dll" "bin\"
if exist "%BIN_DIR%\libgcc_s_dw2-1.dll" copy /Y "%BIN_DIR%\libgcc_s_dw2-1.dll" "bin\"

REM Copy SFML runtime DLLs from the same bin (many installations put them here)
if exist "%BIN_DIR%\libsfml-graphics-2.dll" copy /Y "%BIN_DIR%\libsfml-graphics-2.dll" "bin\"
if exist "%BIN_DIR%\libsfml-window-2.dll" copy /Y "%BIN_DIR%\libsfml-window-2.dll" "bin\"
if exist "%BIN_DIR%\libsfml-system-2.dll" copy /Y "%BIN_DIR%\libsfml-system-2.dll" "bin\"
if exist "%BIN_DIR%\libsfml-audio-2.dll" copy /Y "%BIN_DIR%\libsfml-audio-2.dll" "bin\"

REM Also try variants without "lib" prefix
if exist "%BIN_DIR%\sfml-graphics-2.dll" copy /Y "%BIN_DIR%\sfml-graphics-2.dll" "bin\"
if exist "%BIN_DIR%\sfml-window-2.dll" copy /Y "%BIN_DIR%\sfml-window-2.dll" "bin\"
if exist "%BIN_DIR%\sfml-system-2.dll" copy /Y "%BIN_DIR%\sfml-system-2.dll" "bin\"
if exist "%BIN_DIR%\sfml-audio-2.dll" copy /Y "%BIN_DIR%\sfml-audio-2.dll" "bin\"