//
// Created by Polina Stupak on 17.10.2026.
//

#ifndef ASSIGNMENT3_SAVELOADMANAGER_H
#define ASSIGNMENT3_SAVELOADMANAGER_H

class SaveLoadManager {
    public:
    SaveLoadManager() = default;
    ~SaveLoadManager() = default;
    void SaveBestResult(int res);
    int LoadBestResult();

};

#endif //ASSIGNMENT3_SAVELOADMANAGER_H
