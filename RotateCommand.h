//
// Created by Polina Stupak on 19.10.2026.
//

#ifndef ASSIGNMENT3_ROTATECOMMAND_H
#define ASSIGNMENT3_ROTATECOMMAND_H

#include "Command.h"

class RotateCommand : public Command {
public:
    void execute(Game& g) override;
};

#endif
