//
// Created by Polina Stupak on 19.10.2026.
//

#ifndef ASSIGNMENT3_MOVELEFTCOMMAND_H
#define ASSIGNMENT3_MOVELEFTCOMMAND_H
#include "Command.h"

class Game;

class MoveLeftCommand : public Command {
public:
    void execute(Game& g) override;
};


#endif //ASSIGNMENT3_MOVELEFTCOMMAND_H
