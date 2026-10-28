cmake_minimum_required(VERSION 4.3)
project(assignment3)

set(CMAKE_CXX_STANDARD 20)

add_executable(assignment3 main.cpp
        Tetromino.cpp
        Tetromino.h
        GameState.h
        Action.h
        Point.cpp
        Point.h
        Game.cpp
        Game.h
        Board.cpp
        Board.h
        Color.h
        InputHandler.cpp
        InputHandler.h
        SaveLoadManager.cpp
        SaveLoadManager.h
        Cell.cpp
        Cell.h
        Command.h
        MoveLeftCommand.cpp
        MoveLeftCommand.h
        MoveRightCommand.cpp
        MoveRightCommand.h
        RotateCommand.cpp
        RotateCommand.h
        SoftDropCommand.cpp
        SoftDropCommand.h
        HardDropCommand.cpp
        HardDropCommand.h
        MenuCommand.cpp
        MenuCommand.h
        ExitCommand.cpp
        ExitCommand.h
        RestartCommand.cpp
        RestartCommand.h
        Renderer.cpp
        Renderer.h
)

target_compile_definitions(assignment3 PRIVATE
        ASSETS_DIR="${CMAKE_CURRENT_SOURCE_DIR}/assets/"
)

list(APPEND CMAKE_PREFIX_PATH "/opt/homebrew")

find_package(SFML 3 REQUIRED COMPONENTS Graphics)

target_link_libraries(assignment3 PRIVATE SFML::Graphics)