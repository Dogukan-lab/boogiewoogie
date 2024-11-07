//
// Created by hmkam on 07/11/2024.
//

#ifndef MEMENTOMANAGER_HPP
#define MEMENTOMANAGER_HPP
#include <Caretaker.hpp>

class MementoManager {
public:
    MementoManager(ArtistManager &aManager, TileManager &tManager);
    static void Save();

    static Memento *Undo();

    static Memento *Redo();

private:
    static std::unique_ptr<Caretaker> caretaker;
};


#endif //MEMENTOMANAGER_HPP