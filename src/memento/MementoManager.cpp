//
// Created by hmkam on 07/11/2024.
//

#include "MementoManager.hpp"

std::unique_ptr<Caretaker> MementoManager::caretaker = nullptr;

MementoManager::MementoManager(ArtistManager &aManager, TileManager &tManager) {
    caretaker = std::make_unique<Caretaker>(aManager, tManager);
}

void MementoManager::Save() {
    caretaker->Backup();
}

Memento *MementoManager::Undo() {
    return caretaker->Undo();
}

Memento *MementoManager::Redo() {
    return caretaker->Redo();
}