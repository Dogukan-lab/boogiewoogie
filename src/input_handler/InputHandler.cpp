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
#include "UndoSnapshot.hpp"
#include "RedoSnapshot.hpp"

InputHandler::InputHandler() {
    actionMap[SDL_SCANCODE_SPACE] = std::make_unique<PauseArtist>();
    actionMap[SDL_SCANCODE_RETURN] = std::make_unique<TileInteraction>();
    actionMap[SDL_SCANCODE_O] = std::make_unique<OpenFile>();
    actionMap[SDL_SCANCODE_A] = std::make_unique<RenderArtists>();
    actionMap[SDL_SCANCODE_ESCAPE] = std::make_unique<QuitWindow>();
    actionMap[SDL_SCANCODE_LEFT] = std::make_unique<UndoSnapshot>();
    actionMap[SDL_SCANCODE_RIGHT] = std::make_unique<RedoSnapshot>();
}

InputHandler::~InputHandler() {
    actionMap.clear();
}

Action *InputHandler::GetAction(int keycode) const {
    auto iterator = actionMap.find(keycode);
    if (iterator != actionMap.end()) {
        return iterator->second.get();
    }
    return nullptr;
}

void InputHandler::executeMouse() {
    actionMap[SDL_SCANCODE_RETURN]->Execute();
}