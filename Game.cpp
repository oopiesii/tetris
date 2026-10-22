//
// Created by Polina Stupak on 13.10.2026.
//
#include "Game.h"
#include <iostream>
#include <random>
#include <unistd.h>

#include "Action.h"

void Game::start() {
    system("stty -icanon -echo min 0 time 10");
    loadbestscore();

    while (gm != GameState::GameOver && gm != GameState::Exit) {
        current = generatenewtetromino();
        landed = false;

        if (!spawn(current)) {
            break;
        }

        update();

        if (gm == GameState::Exit) break;

        lockpiece(current);

        int cleared = board.ClearFullLines();
        addpoints(cleared);
    }

    system("stty sane");
    finish();
}

Tetromino Game::generatenewtetromino() {
    static std::mt19937 gen(std::random_device{}());
    static std::uniform_int_distribution<int> dist(0, static_cast<int>(TetrominoType::Count) - 1);
    int random_number = dist(gen);
    TetrominoType type = static_cast<TetrominoType>(random_number);
    std::cout << random_number << '\n';
    return Tetromino(type);
}

void Game::drawtetromino(Tetromino t) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (t.isEmpty(i, j)) {
                std::cout << "    ";
            } else {
                std::cout << "#   ";
            }
        }
        std::cout << '\n';
    }
}

void Game::drawboard(const Tetromino& currenttetromino) {
    std::system("clear");
    std::cout <<"Hello! That is Tetris by Polina Stupak)" << std::endl;
    std::cout <<"Press A to move left, D to move right, S to go down, R to rotate" << std::endl;
    std::cout <<"To go to menu press M" << std::endl;
    std::cout <<"Best score: " << bestscore << "👑" << std::endl;
    std::cout <<"Your score: " << points << std::endl;
    std::array<Point, 4> c = currenttetromino.getCells();
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 10; j++) {
            bool isTetrominoCell = false;

            for (const Point& cell : c) {
                if (cell.getX() == i && cell.getY() == j) {
                    isTetrominoCell = true;
                    break;
                }
            }

            if (isTetrominoCell) {
                std::cout <<getcolor(currenttetromino.getColor()) << "███" << "\033[0m";;
            }
            else if (board.isOccupied(i, j)) {
                std::cout <<getcolor(board.getColor(i,j)) << "███" << "\033[0m";;
            }
            else {
                std::cout << ". .";
            }
        }

        std::cout << '\n';
    }
}

std::string Game::getcolor(Color color) {
    switch (color) {
        case Color::Red:    return "\033[31m";
        case Color::Blue:   return "\033[34m";
        case Color::Green:  return "\033[32m";
        case Color::Yellow: return "\033[33m";
        case Color::Purple: return "\033[35m";
        case Color::Cyan:   return "\033[36m";
        case Color::Orange: return "\033[38;5;208m";
        case Color::None:   return "\033[0m";
    }
    return "\033[0m";
}

void Game::setscore(int score) {
    points += score;
}

void Game::loadbestscore() {
    bestscore = slm.LoadBestResult();
}

void Game::finish() {
    std::system("clear");
    if (gm == GameState::GameOver) {
        std::cout << "GAMEOVER" << std::endl;
    }
    if (points > bestscore) {
        std::cout << "Your new best score: " << points << "!!!" << std::endl;
        bestscore = points;
        slm.SaveBestResult(points);
    }
    std::cout << "Your score: " << points << std::endl;

}

bool Game::ShowMenu() {
    std::system("clear");
    std::cout << "BEST SCORE: " << bestscore << std::endl;
    std::cout << "YOUR CURRENT SCORE: " << points << std::endl;
    std::cout << "To end game enter E" << std::endl;
    std::cout << "To continue game enter C" << std::endl;
    system("stty min 1 time 0");
    bool result = false;
    char key;
    while (read(STDIN_FILENO, &key, 1) > 0) {
        key = std::toupper(key);
        if (key == 'C') {
            gm = GameState::Play;
            result = true;
            break;
        }
        if (key == 'E') {
            gm = GameState::Exit;
            result = false;
            break;
        }
        std::cout << "Enter C or E" << std::endl;
    }
    system("stty min 0 time 10");
    return result;
}

bool Game::spawn(Tetromino t) {
    if (!board.couldBePlaced(t)) {
        gm = GameState::GameOver;
        return false;
    }
    return true;
}

void Game::update() {
    while (!landed && gm != GameState::Exit) {
        drawboard(current);

        auto command = input.getAction();

        if (command) {
            command->execute(*this);
        }
        else if (gm == GameState::Play) {
            softDrop();
        }
    }
}

void Game::lockpiece(Tetromino t) {
    board.blockToBoard(t);
}


void Game::addpoints(int lines) {
    points += 100 * lines;
}

void Game::tryMoveLeft() {
    Tetromino test = current;
    test.moveleft();
    if (board.couldBePlaced(test)) current = test;
}

void Game::tryMoveRight() {
    Tetromino test = current;
    test.moveright();
    if (board.couldBePlaced(test)) current = test;
}

void Game::tryRotate() {
    Tetromino test = current;
    test.rotate();
    if (board.couldBePlaced(test)) current = test;
}

void Game::softDrop() {
    Tetromino test = current;
    test.movedown();
    if (board.couldBePlaced(test)) current = test;
    else landed = true;
}

void Game::hardDrop() {
    Tetromino test = current;
    test.movedown();
    while (board.couldBePlaced(test)) {
        current = test;
        test.movedown();
    }
    landed = true;
}