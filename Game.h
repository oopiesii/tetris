//
// Created by Polina Stupak on 13.10.2026.
//

#ifndef ASSIGNMENT3_GAME_H
#define ASSIGNMENT3_GAME_H
#include <SFML/Graphics/RenderWindow.hpp>

#include "Board.h"
#include "GameState.h"
#include "InputHandler.h"
#include "Renderer.h"
#include "SaveLoadManager.h"
#include "Tetromino.h"


class Game {
    public:
        Game()=default;
        void start();
        void drawboard(const Tetromino& currenttetromino);
        void drawtetromino(Tetromino t);
        std::string getcolor(Color color);
        Tetromino generatenewtetromino();
        void setscore(int score);
        void loadbestscore();
        void finish();
        void ShowMenu();
        bool spawn(Tetromino t);
        void update();
        void lockpiece(Tetromino t);
        void addpoints(int lines);
        void tryMoveRight();
        void tryMoveLeft();
        void tryRotate();
        void softDrop();
        void hardDrop();
        void SaveGame();
        void LoadGame();
        void restart();
        GameState gm = GameState::Play;
        Renderer render = Renderer();
    private:
        Tetromino current{TetrominoType::T};
        bool landed = false;
        InputHandler input = InputHandler();
        Board board = Board();
        SaveLoadManager slm = SaveLoadManager();
        int points = 0;
        int bestscore = 0;
        bool restartRequested = false;
        sf::Clock inputTimer;
        float delay = 0.2f;
        float buttonDelay = 0.15f;
};


#endif //ASSIGNMENT3_GAME_H
