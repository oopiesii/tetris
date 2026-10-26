//
// Created by Polina Stupak on 25.10.2026.
//

#ifndef ASSIGNMENT3_RENDERER_H
#define ASSIGNMENT3_RENDERER_H
#pragma once
#include <SFML/Graphics.hpp>
#include "Board.h"
#include "Tetromino.h"

class Renderer {
    public:
        Renderer();
        bool isOpen() const;
        void close();
        void render(Board& board, const Tetromino& current, int points, int bestpoints);
        sf::RenderWindow& getWindow();
        sf::Color toSFMLcolor(Color color);
        void drawCell(int row, int col, Color color);
        void Menu();
        void drawGameOver(int bestscore, int points );
    private:
        sf::RenderWindow window;
        sf::Texture bannerTexture;
        sf::Texture menuTexture;
        sf::Texture gameoverTexture;
        void drawBoard(Board& board);
        void drawTetromino(const Tetromino& tetromino);
        void drawScore(int score);
        sf::Font font;
};


#endif //ASSIGNMENT3_RENDERER_H
