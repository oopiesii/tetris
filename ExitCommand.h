//
// Created by Polina Stupak on 19.10.2026.
//

#ifndef ASSIGNMENT3_EXITCOMMAND_H
#define ASSIGNMENT3_EXITCOMMAND_H
#include "Command.h"

class ExitCommand : public Command {
public:
    void execute(Game& g) override;
};

#endif //ASSIGNMENT3_EXITCOMMAND_H
