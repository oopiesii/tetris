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
        bool proccessaction(Action action, Tetromino& t);
        void setscore(int score);
        void loadbestscore();
        void finish();
        bool ShowMenu();
        bool spawn(Tetromino t);
        void update(Tetromino& t);
        void lockpiece(Tetromino t);
        void addpoints(int lines);

    private:
        GameState gm = GameState::Play;
        InputHandler input = InputHandler();
        Board board = Board();
        SaveLoadManager slm = SaveLoadManager();
        int points = 0;
        int bestscore = 0;
};


#endif //ASSIGNMENT3_GAME_H
