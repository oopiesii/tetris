//
// Created by Polina Stupak on 19.10.2026.
//

#include "MenuCommand.h"
#include "Game.h"

void MenuCommand::execute(Game& g) {
    g.gm = GameState::Menu;
}