//
// Created by doguk on 10/9/2024.
//

#ifndef BOOGIEWOOGIEAPP_HPP
#define BOOGIEWOOGIEAPP_HPP
#include <memory>
#include <SDL_video.h>

#include "TileManager.hpp"
#include "renderer/BoogieRenderer.hpp"

constexpr bool isRunning = true;

//Immovable object :)
class BoogieWoogieApp {
public:
    BoogieWoogieApp();
    BoogieWoogieApp(const char* windowName, const bool isCentered, const int width, const int height);

    BoogieWoogieApp(const BoogieWoogieApp& other) = delete;
    BoogieWoogieApp operator=(const BoogieWoogieApp& other) = delete;
    BoogieWoogieApp(BoogieWoogieApp&& other) = delete;
    BoogieWoogieApp operator=(BoogieWoogieApp&& other) = delete;

    void SetupSimulation() const;
    void RunSimulation() const;

private:
    std::unique_ptr<SDL_Window, decltype(&SDL_DestroyWindow)> _window;
    std::unique_ptr<BoogieRenderer> _renderer;
    std::unique_ptr<TileManager> _tileManager;

};



#endif //BOOGIEWOOGIEAPP_HPP