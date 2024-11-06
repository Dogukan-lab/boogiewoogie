//
// Created by hmkam on 06/11/2024.
//

#include "Caretaker.hpp"


Caretaker::Caretaker(BoogieRenderer *originator, int mementoSize) : originator_(originator), mementos_(mementoSize) {}

Caretaker::~Caretaker() {
    for (auto m: mementos_) delete m;
}

void Caretaker::Backup() {
    mementos_.push_back(originator_->Save());
    // todo:remove
    std::cout << "Caretaker: Saving Originator's state... Date: " << mementos_.index_front(0)->GetDate();
    // std::cout << "Artist 0 Pos: x: " << mementos_.index_front(0)->GetAritsts().front()->GetPosition().x << " y: "
    // << mementos_.index_front(0)->GetAritsts().front()->GetPosition().y << std::endl << std::endl;
}

void Caretaker::Pause() {
    // if (isPaused()) { return; }
    //
    // pause();
}

void Caretaker::Resume() {
    // if (!isPaused()) { return; }
    //
    // resume();
}

void Caretaker::Undo() {
    if (mementos_.empty()) { return; }

    if (reverseMementoIndex + 1 >= mementos_.size()) { return; }

    Pause();
    reverseMementoIndex++;
    Memento *memento = mementos_.index_front(reverseMementoIndex);

    std::cout << "Caretaker: Restoring state to: " << memento->GetDate() << "\n";
    // std::cout << "Artist 0 Pos: x: " << mementos_.index_front(0)->GetAritsts().front()->GetPosition().x << " y: "
    // << mementos_.index_front(0)->GetAritsts().front()->GetPosition().y << std::endl << std::endl;

    originator_->Restore(memento);
    for (auto artist : mementos_.index_front(reverseMementoIndex)->GetAritsts()) {
        // std::cout << "Artist 0 Pos: x: " << artist.startPos.x << " y: "
        // << artist.startPos.y << std::endl;
    }
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
