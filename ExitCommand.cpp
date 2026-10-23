//
// Created by Polina Stupak on 19.10.2026.
//

#include "ExitCommand.h"
#include "Game.h"
#include "GameState.h"

void ExitCommand::execute(Game& g) {
    g.gm = GameState::Exit;
    g.finish();
}
