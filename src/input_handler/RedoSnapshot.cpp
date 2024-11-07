//
// Created by doguk on 11/7/2024.
//

#include "RedoSnapShot.hpp"
#include "BoogieWoogieApp.hpp"

void RedoSnapshot::Execute() const {
    BoogieWoogieApp::GetInstance().drawInstance = true;

    auto memento = MementoManager::Redo();
    if(memento)
        BoogieWoogieApp::GetInstance().currentMemento = *memento;
//    else
//        std::cout << "UNABLE TO FIND MEMENTO!" << std::endl;
}