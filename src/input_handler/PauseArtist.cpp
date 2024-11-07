//
// Created by hmkam on 27/10/2024.
//

#include <BoogieWoogieApp.hpp>

#include "include/PauseArtists.hpp"
#include <iostream>

void PauseArtist::Execute() const {
    bool& drawInstance = BoogieWoogieApp::GetInstance().drawInstance;
    drawInstance = false;
    bool& running = BoogieWoogieApp::GetInstance().shouldUpdateArtists;
    running = !running;
}