//
// Created by hmkam on 07/11/2024.
//

#include "UndoSnapshot.hpp"

#include <BoogieWoogieApp.hpp>

#include "MementoManager.hpp"

void UndoSnapshot::Execute() const {
    BoogieWoogieApp::GetInstance().drawInstance = true;
//    BoogieWoogieApp::GetInstance().shouldUpdateArtists = false;

    auto memento = MementoManager::Undo();
    if(memento)
        BoogieWoogieApp::GetInstance().currentMemento = *memento;
    else
        std::cout << "UNABLE TO FIND MEMENTO!" << std::endl;
}