//
// Created by doguk on 10/9/2024.
//

#ifndef BOOGIEWOOGIEAPP_HPP
#define BOOGIEWOOGIEAPP_HPP
#include <functional>
#include <memory>
#include <SDL_video.h>

#include "ArtistManager.hpp"
#include "TileManager.hpp"
#include "BoogieRenderer.hpp"
#include "InputHandler.hpp"

//Immovable object :)
class BoogieWoogieApp {
public:

    static BoogieWoogieApp& GetInstance() {
        static BoogieWoogieApp instance;
        return instance;
    }

    BoogieWoogieApp(const char *windowName, bool isCentered, int width, int height);

    BoogieWoogieApp(const BoogieWoogieApp &other) = delete;

    BoogieWoogieApp operator=(const BoogieWoogieApp &other) = delete;

    BoogieWoogieApp(BoogieWoogieApp &&other) = delete;

    BoogieWoogieApp operator=(BoogieWoogieApp &&other) = delete;

    void SetupSimulation();

    TileManager& GetTileManager() const {return *_tileManager;}
    ArtistManager& GetArtistManager() const {return *_artistManager;}
    BoogieRenderer& GetRenderer() const {return *_renderer;}

    void RunSimulation();
    bool shouldUpdateArtists;
    bool isRunning;
    bool artistsLoaded = false;
    bool mapLoaded = false;
    std::unordered_map<std::string, std::function<void(std::vector<std::string>&)>> mapActions;
    std::unordered_map<std::string, std::function<void(std::vector<std::string>&)>> artistActions;
private:
    BoogieWoogieApp();
    std::string mapSource{};
    std::string artistSource{};




    std::unique_ptr<SDL_Window, decltype(&SDL_DestroyWindow)> _window;
    std::unique_ptr<InputHandler> _inputHandler;
    std::unique_ptr<TileManager> _tileManager;
    std::unique_ptr<BoogieRenderer> _renderer;
    std::unique_ptr<ArtistManager> _artistManager;

    void CreateMap(const std::string &source) const;

    void CreateArtists(const std::string &source);
};


#endif //BOOGIEWOOGIEAPP_HPP