//
// Created by Polina Stupak on 19.10.2026.
//

#include "MoveLeftCommand.h"
#include "Game.h"

void MoveLeftCommand::execute(Game& g) {
    g.tryMoveLeft();
}