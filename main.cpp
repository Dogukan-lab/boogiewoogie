#include <TestSuite.hpp>
#include <gtest/gtest.h>

#include "BoogieWoogieApp.hpp"

#define TEST_FRAMEWORK 1

int main(void) {
#if TEST_FRAMEWORK
    return TestSuite::StartTests();
#endif
    // auto& app = BoogieWoogieApp::GetInstance();
    // app.SetupSimulation();
    // app.RunSimulation();
    // return 0;
}