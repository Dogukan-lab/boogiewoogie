// Created by doguk on 10/27/2024.
//

#include "OpenFile.hpp"

#include <BoogieWoogieApp.hpp>
#include <iostream>
#include <FileDialogModule.hpp>
#include <FileReaderFactory.hpp>
#include <FileReader.hpp>

void OpenFile::Execute() const {
    BoogieWoogieApp::GetInstance().shouldUpdateArtists = false;
    auto [succes, path] = FileDialogModule::showDialog();

    if (!succes)
        return;

    auto reader = FileReaderFactory::CreateFileReader(path);
    auto [type, data] = reader->ReadContent();

    std::cout << path << std::endl;

    for (const auto &[key,val]: BoogieWoogieApp::GetInstance().mapActions) {
        if (key == type) {
            val(data);
            BoogieWoogieApp::GetInstance().GetRenderer().RegisterTiles(
                BoogieWoogieApp::GetInstance().GetTileManager().getTiles()
            );
            BoogieWoogieApp::GetInstance().mapLoaded = true;
            BoogieWoogieApp::GetInstance().shouldUpdateArtists = true;
            return;
        }
    }

    for (const auto &[key,val]: BoogieWoogieApp::GetInstance().artistActions) {
        if (key == type) {
            val(data);
            BoogieWoogieApp::GetInstance().GetRenderer().RegisterArtists(
                BoogieWoogieApp::GetInstance().GetArtistManager().GetArtists()
            );
            BoogieWoogieApp::GetInstance().artistsLoaded = true;
            // BoogieWoogieApp::GetInstance().shouldUpdateArtists = true;
            return;
        }
    }
}
