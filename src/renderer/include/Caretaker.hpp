//
// Created by hmkam on 06/11/2024.
//

#ifndef CARETAKER_HPP
#define CARETAKER_HPP
#include <iostream>
#include "CircularBuffer.hpp"

#include "BoogieRenderer.hpp"

class Caretaker {
private:
    CircularBuffer<Memento *> mementos_; //todo ringbuffer van uniqe pointers?
    int reverseMementoIndex = 0; //todo: add ringbuffer remove from head to index ?
    BoogieRenderer *originator_;

public:
    Caretaker(BoogieRenderer *originator, int mementoSize = 100);

    ~Caretaker();

    void Backup();

    void Pause();

    void Resume();

    void Undo();

    uint16_t Size() const;

    void Redo();

    void ShowHistory();
};


#endif //CARETAKER_HPP
