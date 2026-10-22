//
// Created by Polina Stupak on 19.10.2026.
//

#include "SoftDropCommand.h"
#include "Game.h"

void SoftDropCommand::execute(Game& g) {
    g.softDrop();
}