//
// Created by Polina Stupak on 23.10.2026.
//

#ifndef ASSIGNMENT3_RESTARTCOMMAND_H
#define ASSIGNMENT3_RESTARTCOMMAND_H
#include "Board.h"
#include "Command.h"
#include "Game.h"


class RestartCommand : public Command {
public:
    void execute(Game& g) override;
    Board b = Board();
    Game g = Game();
};


#endif //ASSIGNMENT3_RESTARTCOMMAND_H
