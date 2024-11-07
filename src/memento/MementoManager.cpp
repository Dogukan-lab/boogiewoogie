//
// Created by hmkam on 07/11/2024.
//

#include "include/MementoManager.hpp"

#include <stdexcept>

std::unique_ptr<Caretaker> MementoManager::caretaker = nullptr;

void MementoManager::Save() {
    caretaker->Backup();
}

Memento *MementoManager::Undo() {
    return caretaker->Undo();
}

Memento *MementoManager::Redo() {
    return caretaker->Redo();
}