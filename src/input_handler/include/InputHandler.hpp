//
// Created by hmkam on 27/10/2024.
//
#ifndef INPUTHANDLER_HPP
#define INPUTHANDLER_HPP

#include <SDL_keycode.h>
#include <memory>
#include <unordered_map>

class Action;
/**
 * Manage the actions
 */
class InputHandler {
public:
    InputHandler();
    ~InputHandler();

    // void addKey(int keycode, Action *command);
    Action* GetAction(int keycode) const;
    void executeMouse();

private:
    std::unordered_map<SDL_Keycode, std::unique_ptr<Action>> actionMap;
};


#endif //INPUTHANDLER_HPP