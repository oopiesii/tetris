//
// Created by Polina Stupak on 14.10.2026.
//
#include "InputHandler.h"
#include <iostream>
#include <unistd.h>

#include "ExitCommand.h"
#include "HardDropCommand.h"
#include "MenuCommand.h"
#include "MoveLeftCommand.h"
#include "MoveRightCommand.h"
#include "RotateCommand.h"
#include "SoftDropCommand.h"

std::unique_ptr<Command> InputHandler::getAction() {
    char key;

    if (read(STDIN_FILENO, &key, 1) <= 0) {
        return nullptr;
    }

    switch (std::toupper(static_cast<unsigned char>(key))) {
        case 'A': return std::make_unique<MoveLeftCommand>();
        case 'D': return std::make_unique<MoveRightCommand>();
        case 'S': return std::make_unique<SoftDropCommand>();
        case 'R': return std::make_unique<RotateCommand>();
        case '1': return std::make_unique<HardDropCommand>();
        case 'M': return std::make_unique<MenuCommand>();
        case 'E': return std::make_unique<ExitCommand>();

        default: return nullptr;
    }
}//cd ~/CLionProjects/assignment3
//./cmake-build-debuag/assignment3