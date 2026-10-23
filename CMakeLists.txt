cmake_minimum_required(VERSION 4.3)
project(assignment3)

set(CMAKE_CXX_STANDARD 20)

add_executable(assignment3 main.cpp
        Tetromino.cpp
        Tetromino.h
        GameState.cpp
        GameState.h
        Action.cpp
        Action.h
        Point.cpp
        Point.h
        Game.cpp
        Game.h
        Board.cpp
        Board.h
        Color.cpp
        Color.h
        InputHandler.cpp
        InputHandler.h
        SaveLoadManager.cpp
        SaveLoadManager.h
        Cell.cpp
        Cell.h
        Command.cpp
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
)