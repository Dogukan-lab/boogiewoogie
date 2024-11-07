//
// Created by hmkam on 06/11/2024.
//

#include "Caretaker.hpp"

#include <TileManager.hpp>



Caretaker::Caretaker(ArtistManager &artist_manager,TileManager &tileManager, int mementoSize)
    : mementos_(mementoSize),artistManager(artist_manager),tileManager(tileManager)  {  }

Caretaker::~Caretaker() {
    for (auto m: mementos_) delete m;
}

void Caretaker::Backup() {
    if (reverseMementoIndex > 0) {
        reverseMementoIndex++;
    }
    mementos_.push_back(new Memento(artistManager.Save(),tileManager.Save()));
}

Memento *Caretaker::Redo() {
    if (mementos_.empty()) { return nullptr; }


    if (reverseMementoIndex - 1 < 0) {
        reverseMementoIndex = mementos_.size();
        return nullptr;
    }//return mementos_.index_front(reverseMementoIndex) } //of reverseMementoIndex

    reverseMementoIndex--;
    Memento *memento = mementos_.index_front(reverseMementoIndex);

    return memento;
}


Memento *Caretaker::Undo() {
    if (mementos_.empty()) { return nullptr; }

    if (reverseMementoIndex + 1 >= mementos_.size()) {
        reverseMementoIndex = 0;
        return nullptr;
    }

    reverseMementoIndex++;
    Memento *memento = mementos_.index_front(reverseMementoIndex);

    std::cout << "Caretaker: Restoring state to: " << memento->GetDate() << "\n";

    // originator_->Restore(memento);

    return memento;
}


uint16_t Caretaker::Size() const {
    return mementos_.size();
}

void Caretaker::ShowHistory() {
    std::cout << "Caretaker: Here's the list of mementos:\n";
    for (const Memento *memento: mementos_) {
        std::cout << memento->GetDate() << "\n";
    }
}