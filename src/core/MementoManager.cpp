//
// Created by hmkam on 07/11/2024.
//

#include "MementoManager.hpp"

#include <stdexcept>

std::unique_ptr<Caretaker> MementoManager::caretaker = nullptr;

void MementoManager::Save() {
    caretaker->Backup();
}

Memento *MementoManager::Undo() {
    return caretaker->Undo();
}

Memento *MementoManager::Redo() {
    return nullptr; //->Redo();
}

void MementoManager::Pause() {
    throw std::runtime_error("MementoManager::Pause not implemented yet.");
}
void MementoManager::Resume() {
    throw std::runtime_error("MementoManager::Resume not implemented yet.");
}