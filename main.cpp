#include <iostream>

#include "src/BoogieWoogieApp.hpp"

int main(void) {
    BoogieWoogieApp app{};

    app.SetupSimulation();
    app.RunSimulation();

    return 0;
}