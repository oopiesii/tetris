//
// Created by Polina Stupak on 19.10.2026.
//

#ifndef ASSIGNMENT3_HARDDROPCOMMAND_H
#define ASSIGNMENT3_HARDDROPCOMMAND_H
#include "Command.h"


class Game;

class HardDropCommand : public Command {
public:
    void execute(Game& g) override;
};



#endif //ASSIGNMENT3_HARDDROPCOMMAND_H
