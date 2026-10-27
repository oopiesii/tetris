//
// Created by Polina Stupak on 25.10.2026.
//

#include "Renderer.h"
Renderer::Renderer(): window(sf::VideoMode({600, 800}), "Tetris by Polina Stupak"){window.setFramerateLimit(60);if (!bannerTexture.loadFromFile("../baner.png")) {
    throw std::runtime_error("Cannot load baner.png");
}
font.openFromFile("../PressStart2P-Regular.ttf");
    if (!menuTexture.loadFromFile("../Polina’s Neon Tetris Pause Menu.png")) {
        throw std::runtime_error("Cannot load");
    }
    if (!gameoverTexture.loadFromFile("../Neon Tetris game over screen.png")) {
        throw std::runtime_error("Cannot load");
    }
}

sf::Color Renderer::toSFMLcolor(Color color) {
    switch (color) {
        case Color::Cyan:   return sf::Color(0, 210, 255);
        case Color::Yellow: return sf::Color(255, 220, 0);
        case Color::Purple: return sf::Color(190, 40, 255);
        case Color::Green:  return sf::Color(30, 240, 65);
        case Color::Red:    return sf::Color(255, 45, 35);
        case Color::Blue:   return sf::Color(45, 80, 255);
        case Color::Orange: return sf::Color(255, 155, 0);
        case Color::None:   return sf::Color(12, 15, 85);
    }
    return sf::Color(12, 15, 85);
}

void Renderer::drawCell(int row, int col, Color color) {
    float cell_size = 28.f;
    float xstart = 150.f;
    float ystart = 220.f;
    sf::RectangleShape block({cell_size - 2, cell_size - 2});
    block.setPosition({xstart + col*cell_size + 1, ystart + row * cell_size + 1});
    block.setFillColor(toSFMLcolor(color));
    window.draw(block);
}

void Renderer::drawBoard(Board& board) {
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 10; j++) {
            drawCell(i, j, board.getColor(i, j));
        }
    }
}

void Renderer::drawTetromino(const Tetromino& tetromino) {
    std::array<Point, 4> cells = tetromino.getCells();
    for (const Point& cell : cells) {
        drawCell(cell.getX(),cell.getY(), tetromino.getColor());
    }
}

void Renderer::render(Board& board, const Tetromino& current, int points, int bestpoints) {
    window.clear(sf::Color(3, 8, 40));
    sf::Sprite banner(bannerTexture);
    sf::Text text(font);
    text.setCharacterSize(16);
    text.setString(
        "SCORE: \n" + std::to_string(points) +
        "\n\nBEST: \n" + std::to_string(bestpoints)
    );
    text.setFillColor(sf::Color(245, 235, 255));
    text.setPosition({15.f, 240.f});    banner.setPosition({0.f, 0.f});
    banner.setScale({600.f / bannerTexture.getSize().x, 200.f / bannerTexture.getSize().y});
    window.draw(banner);
    window.draw(text);
    drawBoard(board);
    drawTetromino(current);
    window.display();
}

sf::RenderWindow& Renderer::getWindow() {
    return window;
}

bool Renderer::isOpen() const {
    return window.isOpen();
}

void Renderer::close() {
    window.close();
}

void Renderer::Menu() {
    window.clear(sf::Color(3, 8, 40));
    sf::Sprite pause(menuTexture);
    pause.setScale({600.f / menuTexture.getSize().x, 800.f / menuTexture.getSize().y});
    window.draw(pause);
    window.display();
}
void Renderer::drawGameOver(int bestscore, int points) {
    window.clear(sf::Color(3, 8, 40));
    sf::Sprite gameover(gameoverTexture);
    gameover.setScale({600.f / gameoverTexture.getSize().x, 800.f / gameoverTexture.getSize().y});
    sf::Text text(font);
    text.setCharacterSize(23);
    text.setString(
        "SCORE: " + std::to_string(points) +
        "\n\nBEST: " + std::to_string(bestscore)
    );
    text.setFillColor(sf::Color(245, 235, 255));
    text.setPosition({200.f, 380.f});
    window.draw(gameover);
    window.draw(text);
    window.display();
}