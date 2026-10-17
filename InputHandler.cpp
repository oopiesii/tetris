//
// Created by Polina Stupak on 14.10.2026.
//
#include "InputHandler.h"

#include <iostream>
Action InputHandler::getAction() {
    char key;
    std::cin >> key;
    key = std::toupper(key);
    switch (key) {
        case 'A': return Action::MoveLeft;
        case 'D': return Action::MoveRight;
        case 'S': return Action::MoveDown;
        case 'R': return Action::Rotate;
        case 'M': return Action::Menu;
        case 'P': return Action::Pause;
        case '1': return Action::HardDrop;
        case 'E': return Action::Exit;
        default:  return Action::None;
    }
}
