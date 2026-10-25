//
// Created by Polina Stupak on 13.10.2026.
//

#ifndef ASSIGNMENT3_GAME_H
#define ASSIGNMENT3_GAME_H
#include "Board.h"
#include "GameState.h"
#include "InputHandler.h"
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
        bool ShowMenu();
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
    private:
        Tetromino current{TetrominoType::T};
        bool landed = false;
        InputHandler input = InputHandler();
        Board board = Board();
        SaveLoadManager slm = SaveLoadManager();
        int points = 0;
        int bestscore = 0;
        bool restartRequested = false;
};


#endif //ASSIGNMENT3_GAME_H
