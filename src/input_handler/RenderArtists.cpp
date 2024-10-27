//
// Created by hmkam on 27/10/2024.
//

#include "include/RenderArtists.hpp"

#include <BoogieWoogieApp.hpp>
#include <iostream>

void RenderArtists::Execute() const {
    bool& statement = BoogieWoogieApp::GetInstance().GetRenderer().shouldRenderArtist;
    statement = !statement;
}
