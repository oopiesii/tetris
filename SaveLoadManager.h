//
// Created by Polina Stupak on 17.10.2026.
//

#ifndef ASSIGNMENT3_SAVELOADMANAGER_H
#define ASSIGNMENT3_SAVELOADMANAGER_H
#include "Board.h"

class SaveLoadManager {
    public:
    SaveLoadManager() = default;
    ~SaveLoadManager() = default;
    void SaveBestResult(int res);
    int LoadBestResult();
    void SaveCurrentBoard(const std::vector<std::vector<Cell>>& cells);
    bool LoadGame(std::vector<std::vector<Cell>>& cells);
};

#endif //ASSIGNMENT3_SAVELOADMANAGER_H
