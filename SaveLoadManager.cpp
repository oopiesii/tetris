//
// Created by Polina Stupak on 17.10.2026.
//

#include "SaveLoadManager.h"
#include <fstream>
#include <iostream>

void SaveLoadManager::SaveBestResult(int res) {
    std::ofstream file("BestResultTetris.txt");
    if (file.is_open()) {
        file << res << std::endl;
    }
}

int SaveLoadManager::LoadBestResult() {
    std::ifstream file("BestResultTetris.txt");
    int bestresult = 0;
    if (file.is_open()) {
       file >> bestresult;
    }
    return bestresult;
}

void SaveLoadManager::SaveCurrentBoard(const std::vector<std::vector<Cell>>& cells) {
    std::ofstream file("GameTetris.txt");
    if (file.is_open()) {
        for (const std::vector<Cell>& row : cells) {
            for (const Cell& cell : row) {
                file << static_cast<int>(cell.getColor()) << " ";
            }
            file << "\n";
        }
    }
}

bool SaveLoadManager::LoadGame(std::vector<std::vector<Cell>>& cells) {
    std::ifstream file("GameTetris.txt");
    if (!file.is_open()) {
        return false;
    }
    std::vector<std::vector<Cell>> loaded = cells;
    int color;
    for (std::vector<Cell>& row : loaded) {
        for (Cell& cell : row) {
            if (!(file >> color)) {
                return false;
            }
            if (color < 0 || color > static_cast<int>(Color::None)) {
                return false;
            }
            cell.setColor(static_cast<Color>(color));
        }
    }
    cells = loaded;
    return true;
}