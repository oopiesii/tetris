//
// Created by Polina Stupak on 19.10.2026.
//

#include "HardDropCommand.h"

#include "Game.h"
class Game;

void HardDropCommand::execute(Game& g) {
    g.hardDrop();
}
