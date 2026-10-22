//
// Created by Polina Stupak on 19.10.2026.
//

#include "MoveRightCommand.h"
#include "Game.h"

void MoveRightCommand::execute(Game& g) {
    g.tryMoveRight();
}