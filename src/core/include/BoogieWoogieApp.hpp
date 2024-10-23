//
// Created by doguk on 10/9/2024.
//

#ifndef BOOGIEWOOGIEAPP_HPP
#define BOOGIEWOOGIEAPP_HPP
#include <memory>
#include <SDL_video.h>

#include "ArtistManager.hpp"
#include "TileManager.hpp"
#include "BoogieRenderer.hpp"

//Immovable object :)
class BoogieWoogieApp {
public:
    BoogieWoogieApp();
    BoogieWoogieApp(const char* windowName, bool isCentered, int width, int height);

    BoogieWoogieApp(const BoogieWoogieApp& other) = delete;
    BoogieWoogieApp operator=(const BoogieWoogieApp& other) = delete;
    BoogieWoogieApp(BoogieWoogieApp&& other) = delete;
    BoogieWoogieApp operator=(BoogieWoogieApp&& other) = delete;

    void SetupSimulation();
    void RunSimulation();

private:
    bool isRunning;
    std::unique_ptr<SDL_Window, decltype(&SDL_DestroyWindow)> _window;
    std::unique_ptr<BoogieRenderer> _renderer;
    std::unique_ptr<TileManager> _tileManager;
    std::unique_ptr<ArtistManager> _artistManager;

};



#endif //BOOGIEWOOGIEAPP_HPP
