//
// Created by hmkam on 27/10/2024.
//

#ifndef MOVEARTISTS_HPP
#define MOVEARTISTS_HPP

#include "Action.hpp"

class MoveArtists : public Action {
public:
    explicit MoveArtists() = default;

    ~MoveArtists() override = default;

    void Execute() const override;
};


#endif //MOVEARTISTS_HPP
