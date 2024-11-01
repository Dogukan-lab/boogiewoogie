#include <TestSuite.hpp>

#include "BoogieWoogieApp.hpp"

#define TEST 0

int main(void) {
#if TEST
    return TestSuite::StartTests();
#endif
    auto& app = BoogieWoogieApp::GetInstance();
    app.SetupSimulation();
    app.RunSimulation();
    return 0;
}
