g++ -o "bin/Swords & Magic.exe" main.cpp ^
    "src/Sources/Game.cpp" ^
    "src/Sources/HomeScreen.cpp" ^
    "src/Sources/HowToPlayScreen.cpp" ^
    "src/Sources/Entity.cpp" ^
    "src/Sources/Player.cpp" ^
    "src/Sources/Enemy.cpp" ^
    "src/Sources/FlyingDemon.cpp" ^
    "src/Sources/Skeleton.cpp" ^
    "src/Sources/GameRoom.cpp" ^
    "src/Sources/Score.cpp" ^
    resource.o -I"include" -L"lib" -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio