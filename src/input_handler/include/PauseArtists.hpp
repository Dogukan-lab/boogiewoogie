//
// Created by hmkam on 27/10/2024.
//

#ifndef MOVEARTISTS_HPP
#define MOVEARTISTS_HPP
#include "Action.hpp"

class PauseArtist : public Action {
public:
    void Execute() const override;
};


#endif //MOVEARTISTS_HPP
