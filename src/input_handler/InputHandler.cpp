//
// Created by hmkam on 27/10/2024.
//
#include <iostream>
#include "include/InputHandler.hpp"

#include <OpenFile.hpp>
#include <PauseArtists.hpp>
#include <QuitWindow.hpp>
#include <RenderArtists.hpp>
#include <TileInteraction.hpp>

InputHandler::InputHandler() {
    actionMap[SDL_SCANCODE_SPACE] = std::make_unique<PauseArtist>();
    actionMap[SDL_SCANCODE_RETURN] = std::make_unique<TileInteraction>();
    actionMap[SDL_SCANCODE_O] = std::make_unique<OpenFile>();
    actionMap[SDL_SCANCODE_A] = std::make_unique<RenderArtists>();
    actionMap[SDL_SCANCODE_ESCAPE] = std::make_unique<QuitWindow>();
}

InputHandler::~InputHandler() {
    actionMap.clear();
}

void InputHandler::executeKey(int keycode) {
    if (actionMap.find(keycode) != actionMap.end()) {
        actionMap[keycode]->Execute();
    } else {
        std::cout << "No command bound to input: " << keycode << std::endl;
    }
}

void InputHandler::executeMouse() {
    actionMap[SDL_SCANCODE_RETURN]->Execute();
}
