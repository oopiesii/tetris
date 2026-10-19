//
// Created by Polina Stupak on 19.10.2026.
//

#ifndef ASSIGNMENT3_MENUCOMMAND_H
#define ASSIGNMENT3_MENUCOMMAND_H

#include "Command.h"

class MenuCommand : public Command {
public:
    void execute(Game& g) override;
};


#endif //ASSIGNMENT3_MENUCOMMAND_H
