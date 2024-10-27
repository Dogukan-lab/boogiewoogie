//
// Created by hmkam on 27/10/2024.
//
#ifndef INPUTHANDLER_HPP
#define INPUTHANDLER_HPP

#include <unordered_map>
#include "AdjustBoxAtMousePointer.hpp"

/**
 * Manage the actions
 */
class InputHandler {
public:
    ~InputHandler();

    void addKey(int keycode, Action *command);

    void executeKey(int keycode);

private:
    std::unordered_map<int, Action *> actionMap;;
};


#endif //INPUTHANDLER_HPP
