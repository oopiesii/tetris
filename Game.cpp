//
// Created by Polina Stupak on 13.10.2026.
//
#include "Game.h"
#include <iostream>
#include <random>

#include "ExitCommand.h"
#include "MoveLeftCommand.h"

void Game::start() {
    system("stty -icanon -echo min 0 time 10");
    loadbestscore();
    LoadGame();
    while (gm != GameState::GameOver && gm != GameState::Exit) {
        current = generatenewtetromino();
        landed = false;

        if (!spawn(current)) {
            break;
        }
        update();

        if (restartRequested) {
            restartRequested = false;
            board.ClearBoard();
            points = 0;
            landed = false;
            gm = GameState::Play;
            continue;
        }

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
    render.render(board, currenttetromino, points, bestscore);
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
    if (points > bestscore) {
        bestscore = points;
        slm.SaveBestResult(bestscore);
    }
    if (gm != GameState::GameOver) {
        return;
    }
    board.ClearBoard();
    SaveGame();
    while (render.isOpen()) {
        while (const auto event = render.getWindow().pollEvent()) {
            if (event->is<sf::Event::Closed>()) {
                render.close();
            }
        }
        if (!render.isOpen()) {
            break;
        }
        render.drawGameOver(bestscore, points);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::E)) {
            break;
        }
    }
}

void Game::ShowMenu() {
    gm = GameState::Menu;
    bool result = false;
    if (inputTimer.getElapsedTime().asSeconds() >= buttonDelay) {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::C)) {
            inputTimer.restart();
            gm = GameState::Play;
            result = true;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::E)) {
            inputTimer.restart();
            SaveGame();
            gm = GameState::Exit;
            result = false;
        }
    }
    render.Menu();
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
        while (const auto event = render.getWindow().pollEvent()) {
            if (event->is<sf::Event::Closed>()) {
                render.close();
                gm = GameState::Exit;
                return;
            }
        }
        if (!render.isOpen()) {
            gm = GameState::Exit;
            return;
        }
        std::unique_ptr<Command> command = input.getAction();
        if (command) {
            command->execute(*this);
        }
        if (gm == GameState::Exit || restartRequested) {
            return;
        }
        if (gm == GameState::Menu) {
            ShowMenu();
            continue;
        }
        if (inputTimer.getElapsedTime().asSeconds() >= delay) {
            if (gm == GameState::Play) {
                inputTimer.restart();
                softDrop();
            }
        }
        drawboard(current);
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
void Game::SaveGame() {
    slm.SaveCurrentBoard(board.GetCells());
}
void Game::LoadGame() {
    slm.LoadGame(board.GetCells());
}
void Game::restart() {
    restartRequested = true;
    landed = true;
}