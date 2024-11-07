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
    CircularBuffer<Memento *> mementos_; //todo ringbuffer van uniqe pointers?
    int reverseMementoIndex = 0; //todo: add ringbuffer remove from head to index ?

    ArtistManager &artistManager;
    TileManager &tileManager;

public:
    Caretaker(ArtistManager &artist_manager, TileManager &tileManager, int mementoSize = 100);

    ~Caretaker();

    void Backup();

    Memento *Undo();

    uint16_t Size() const;

    void Redo();

    void ShowHistory();
};


#endif //CARETAKER_HPP