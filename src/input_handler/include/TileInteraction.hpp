//
// Created by doguk on 10/27/2024.
//

#ifndef TILEINTERACTION_HPP
#define TILEINTERACTION_HPP

#include "Action.hpp"

class TileInteraction: public Action {
public:
    void Execute() const override;
};

#endif //TILEINTERACTION_HPP
