//
// Created by hmkam on 06/11/2024.
//

#include "Caretaker.hpp"

#include <TileManager.hpp>



Caretaker::Caretaker(ArtistManager &artist_manager,TileManager &tileManager, int mementoSize)
    : _memento(mementoSize), artistManager(artist_manager), tileManager(tileManager)  {  }

Caretaker::~Caretaker() {
    for (auto m: _memento) delete m;
}

void Caretaker::Backup() {
    if (reverseMementoIndex > 0) {
        reverseMementoIndex++;
    }
    _memento.push_back(new Memento(artistManager.Save(), tileManager.Save()));
}

Memento *Caretaker::Redo() {
    if (_memento.empty()) { return nullptr; }

    if (reverseMementoIndex - 1 < 0) {
        reverseMementoIndex = _memento.size();
        return nullptr;
    }

    reverseMementoIndex--;
    Memento *memento = _memento.index_front(reverseMementoIndex);

    return memento;
}


Memento *Caretaker::Undo() {
    if (_memento.empty()) {
        return nullptr;
    }

    if (reverseMementoIndex + 1 >= _memento.size()) {
        reverseMementoIndex = 0;
        return nullptr;
    }

    reverseMementoIndex++;
    Memento *memento = _memento.index_front(reverseMementoIndex);

    std::cout << "Caretaker: Restoring state to: " << memento->GetDate() << "\n";

    // originator_->Restore(memento);
    return memento;
}


size_t Caretaker::Size() const {
    return _memento.size();
}

void Caretaker::ShowHistory() {
    std::cout << "Caretaker: Here's the list of mementos:\n";
    for (const Memento *memento: _memento) {
        std::cout << memento->GetDate() << "\n";
    }
}