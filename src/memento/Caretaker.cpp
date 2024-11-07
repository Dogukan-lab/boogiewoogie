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
    mementos_.push_back(new Memento(artistManager.Save(),tileManager.Save()));
}

Memento *Caretaker::Undo() {
    if (mementos_.empty()) { return nullptr; }

    if (reverseMementoIndex + 1 >= mementos_.size()) { return nullptr; }

    reverseMementoIndex++;
    Memento *memento = mementos_.index_front(reverseMementoIndex);

    std::cout << "Caretaker: Restoring state to: " << memento->GetDate() << "\n";
    // std::cout << "Artist 0 Pos: x: " << mementos_.index_front(0)->GetAritsts().front()->GetPosition().x << " y: "
    // << mementos_.index_front(0)->GetAritsts().front()->GetPosition().y << std::endl << std::endl;

    // originator_->Restore(memento);
    for (auto artist : mementos_.index_front(reverseMementoIndex)->GetAritsts()) {
        // std::cout << "Artist 0 Pos: x: " << artist.startPos.x << " y: "
        // << artist.startPos.y << std::endl;
    }

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