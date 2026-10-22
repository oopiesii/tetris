//
// Created by Polina Stupak on 19.10.2026.
//

#include "RotateCommand.h"
#include "Game.h"

void RotateCommand::execute(Game& g) {
    g.tryRotate();
}