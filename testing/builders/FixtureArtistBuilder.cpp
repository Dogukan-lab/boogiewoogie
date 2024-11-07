//
// Created by doguk on 11/7/2024.
//

#include "FixtureArtistBuilder.hpp"

TEST_F(FixtureArtistBuilder, BuildSingleArtist) {
    auto artists = builder->addArtist(entries[0]).build();
    auto& artist = artists[0];

    EXPECT_EQ(artist->GetPosition().x,0);
    EXPECT_EQ(artist->GetPosition().y,0);
    EXPECT_EQ(artist->GetDirection().x,2);
    EXPECT_EQ(artist->GetDirection().y,1);
}

TEST_F(FixtureArtistBuilder, CheckEmptyEntries) {}