//
// Created by Polina Stupak on 23.10.2026.
//

#include "RestartCommand.h"
void RestartCommand::execute(Game& g) {
    b.ClearBoard();
    g.start();
}