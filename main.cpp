#include <TestSuite.hpp>
#include <gtest/gtest.h>

#include "BoogieWoogieApp.hpp"

#define TEST 1

int main(void) {
#ifdef TEST
    return TestSuite::StartTests();
#endif
    // auto& app = BoogieWoogieApp::GetInstance();
    // app.SetupSimulation();
    // app.RunSimulation();
    // return 0;
}