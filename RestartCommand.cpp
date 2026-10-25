//
// Created by Polina Stupak on 23.10.2026.
//

#include "RestartCommand.h"
#include "Game.h"

void RestartCommand::execute(Game& g) {
    g.restart();
}