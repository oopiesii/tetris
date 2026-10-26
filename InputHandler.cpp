//
// Created by Polina Stupak on 14.10.2026.
//
#include "InputHandler.h"
#include <iostream>
#include <unistd.h>

#include "ExitCommand.h"
#include "HardDropCommand.h"
#include "MenuCommand.h"
#include "MoveLeftCommand.h"
#include "MoveRightCommand.h"
#include "RestartCommand.h"
#include "RotateCommand.h"
#include "SoftDropCommand.h"

std::unique_ptr<Command> InputHandler::getAction() {
    if (inputTimer.getElapsedTime().asSeconds() >= delay) {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) {
            inputTimer.restart();
            return std::make_unique<MoveLeftCommand>();
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {
            inputTimer.restart();
            return std::make_unique<MoveRightCommand>();
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) {
            inputTimer.restart();
            return std::make_unique<SoftDropCommand>();
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::R)) {
            inputTimer.restart();
            return std::make_unique<RotateCommand>();
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::M)) {
            inputTimer.restart();
            return std::make_unique<MenuCommand>();
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::E)) {
            inputTimer.restart();
            return std::make_unique<ExitCommand>();
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::H)) {
            inputTimer.restart();
            return std::make_unique<RestartCommand>();
        }
        return nullptr;
    }
    if (inputTimer.getElapsedTime().asSeconds() < delay) {
        return nullptr;
    }
}