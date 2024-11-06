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
    //todo:remove
    std::cout << "Caretaker: Saving Originator's state... Date: " << mementos_.index_front(0)->GetDate() << std::endl;
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
    originator_->Restore(memento);
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
