//
// Created by Polina Stupak on 14.10.2026.
//

#ifndef ASSIGNMENT3_INPUTHANDLER_H
#define ASSIGNMENT3_INPUTHANDLER_H
#include "Action.h"

class InputHandler {
    public:
        InputHandler()=default;
        Action getAction();
        char key;
};

#endif //ASSIGNMENT3_INPUTHANDLER_H
