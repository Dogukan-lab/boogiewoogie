#include "BoogieWoogieApp.hpp"

int main(void) {
    auto& app = BoogieWoogieApp::GetInstance();
    app.SetupSimulation();
    app.RunSimulation();
    return 0;
}
