//
// Created by Polina Stupak on 14.10.2026.
//
#include "InputHandler.h"
#include <iostream>
#include <unistd.h>
Action InputHandler::getAction() {
    char key;
    while (read(STDIN_FILENO, &key, 1) > 0) {
        switch (std::toupper(key)) {
            case 'A': return Action::MoveLeft;
            case 'D': return Action::MoveRight;
            case 'S': return Action::MoveDown;
            case 'R': return Action::Rotate;
            case 'M': return Action::Menu;
            case 'P': return Action::Pause;
            case '1': return Action::HardDrop;
            case 'E': return Action::Exit;
            default:  break;
        }
    }
    return Action::None;
}//cd ~/CLionProjects/assignment3
//./cmake-build-debuag/assignment3