//
// Created by hmkam on 06/11/2024.
//

#ifndef CARETAKER_HPP
#define CARETAKER_HPP
#include "ArtistManager.hpp"
#include "TileManager.hpp"

#include "CircularBuffer.hpp"


class Caretaker {
private:
    CircularBuffer<Memento *> _memento;
    int reverseMementoIndex = 0;

    ArtistManager &artistManager;
    TileManager &tileManager;

public:
    Caretaker(ArtistManager &artist_manager, TileManager &tileManager, int mementoSize = 100);

    ~Caretaker();

    void Backup();

    Memento *Undo();

    size_t Size() const;

    Memento *Redo();

    void ShowHistory();
};


#endif //CARETAKER_HPP