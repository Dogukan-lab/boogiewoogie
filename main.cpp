#include <iostream>

#include "src/BoogieWoogieApp.hpp"

int main(void) {
    BoogieWoogieApp::SetupSimulation();
    BoogieWoogieApp::RunSimulation();

    std::cout << "Hello, World!" << std::endl;
    return 0;
}
