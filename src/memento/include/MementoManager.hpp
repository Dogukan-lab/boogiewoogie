//
// Created by hmkam on 07/11/2024.
//

#ifndef MEMENTOMANAGER_HPP
#define MEMENTOMANAGER_HPP

#include "ArtistManager.hpp"
#include "Caretaker.hpp"
#include "TileManager.hpp"

class MementoManager {
public:
    MementoManager(ArtistManager &aManager, TileManager &tManager) : artistManager(aManager), tileManager(tManager) {
        caretaker = std::make_unique<Caretaker>(aManager, tManager);
    }

    static void Save();

    static Memento *Undo();

    static Memento *Redo();

private:
    ArtistManager &artistManager;
    TileManager &tileManager;
    static std::unique_ptr<Caretaker> caretaker;
};


#endif //MEMENTOMANAGER_HPP