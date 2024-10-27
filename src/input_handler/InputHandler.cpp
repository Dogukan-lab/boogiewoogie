//
// Created by hmkam on 27/10/2024.
//
#include <iostream>
#include "InputHandler.hpp"


InputHandler::~InputHandler() {
    for (auto [key, action]: actionMap) {
        delete action;
    }
    actionMap.erase(this->actionMap.begin(), this->actionMap.end());
}

void InputHandler::addKey(int keycode, Action *command) {
    actionMap[keycode] = command;
}

void InputHandler::executeKey(int keycode) {
    if (actionMap.find(keycode) != actionMap.end()) {
        actionMap[keycode]->Execute();
    } else {
        std::cout << "No command bound to input: " << keycode << std::endl;
    }
}
