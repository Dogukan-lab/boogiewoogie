//
// Created by hmkam on 07/11/2024.
//

#include "UndoSnapshot.hpp"

#include <BoogieWoogieApp.hpp>

#include "../core/MementoManager.hpp"

void UndoSnapshot::Execute() const {
    BoogieWoogieApp::GetInstance().shouldUpdateArtists = true;

    auto & snapshot = BoogieWoogieApp::GetInstance().currentMemento;
    snapshot=*MementoManager::Undo();
}
