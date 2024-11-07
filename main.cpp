#include <TestSuite.hpp>

#include "BoogieWoogieApp.hpp"

#define TEST_FRAMEWORK 0

int main(void) {
#if TEST_FRAMEWORK
    return TestMain::StartTests();
#endif
    auto& app = BoogieWoogieApp::GetInstance();
    app.SetupSimulation();
    app.RunSimulation();
    return 0;
}