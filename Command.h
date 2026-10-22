//
// Created by Polina Stupak on 19.10.2026.
//

#ifndef ASSIGNMENT3_COMMAND_H
#define ASSIGNMENT3_COMMAND_H


class Game;

class Command {
public:
    virtual ~Command() = default;
    virtual void execute(Game& g) = 0;
};


#endif //ASSIGNMENT3_COMMAND_H
