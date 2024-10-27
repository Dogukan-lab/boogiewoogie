//
// Created by hmkam on 27/10/2024.
//

#include <BoogieWoogieApp.hpp>

#include "include/PauseArtists.hpp"
#include <iostream>

void PauseArtist::Execute() const {
    std::cout << "Move artists: todo: implement\n";
    //todo: implement
    bool& running = BoogieWoogieApp::GetInstance().shouldUpdateArtists;
    running = !running;
}
