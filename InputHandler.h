//
// Created by Polina Stupak on 14.10.2026.
//

#ifndef ASSIGNMENT3_INPUTHANDLER_H
#define ASSIGNMENT3_INPUTHANDLER_H
#include <memory>

#include "Action.h"
#include "Command.h"

class InputHandler {
    public:
        InputHandler()=default;
        std::unique_ptr<Command> getAction();
};

#endif //ASSIGNMENT3_INPUTHANDLER_H
