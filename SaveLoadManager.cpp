//
// Created by Polina Stupak on 17.10.2026.
//

#include "SaveLoadManager.h"

#include <fstream>

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
