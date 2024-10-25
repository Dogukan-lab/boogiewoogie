#include <filesystem>
#include <iostream>
#include "BoogieWoogieApp.hpp"
#include "src/fileparsing/FileReaderFactory.hpp"
#include "src/fileparsing/FileReader.hpp"

void fileParsingTest() {
    std::string webSource = "https://firebasestorage.googleapis.com/v0/b/dpa-files.appspot.com/o/grid.txt?alt=media";
    std::string diskSource = R"(../assets/artist.csv)";

    const auto &reader = FileReaderFactory::CreateFileReader(webSource);

    const auto [fileType, lines] = reader->ReadContent(webSource);

    // std::cout << "FILE TYPE IS: " << fileType << std::endl;
    // std::cout << "----BEGINNING OF READING----" << std::endl;
    // for (const auto &line: lines) {
        // std::cout << line << "\n";
    // }
    // std::cout << "----END OF READING----" << std::endl;
}


int main(void) {
    // BoogieWoogieApp app{};
    // app.SetupSimulation();
    // app.RunSimulation();
    fileParsingTest();

    return 0;
}
