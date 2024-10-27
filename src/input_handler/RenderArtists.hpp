//
// Created by hmkam on 27/10/2024.
//

#ifndef RENDERARTISTS_HPP
#define RENDERARTISTS_HPP
#include "Action.hpp"


class RenderArtists : public Action {
public:
    explicit RenderArtists() = default;

    ~RenderArtists() override = default;

    void Execute() const override;
};


#endif //RENDERARTISTS_HPP
