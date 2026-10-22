//
// Created by Polina Stupak on 19.10.2026.
//

#ifndef ASSIGNMENT3_SOFTDROPCOMMAND_H
#define ASSIGNMENT3_SOFTDROPCOMMAND_H
#include "Command.h"


class Game;

class SoftDropCommand : public Command {
public:
    void execute(Game& g) override;
};

#endif //ASSIGNMENT3_SOFTDROPCOMMAND_H
