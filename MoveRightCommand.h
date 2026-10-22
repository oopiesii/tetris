//
// Created by Polina Stupak on 19.10.2026.
//

#ifndef ASSIGNMENT3_MOVEIGHTCOMMAND_H
#define ASSIGNMENT3_MOVEIGHTCOMMAND_H
#include "Command.h"

class Game;

class MoveRightCommand : public Command {
public:
    void execute(Game& g) override;
};


#endif //ASSIGNMENT3_MOVEIGHTCOMMAND_H
