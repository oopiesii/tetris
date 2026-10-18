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
)