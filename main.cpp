#include <FileReader.hpp>
#include <FileReaderFactory.hpp>
#include <TestSuite.hpp>
#include <gtest/gtest.h>

#include "BoogieWoogieApp.hpp"
#include "TxtParser.hpp"

#define TEST_FRAMEWORK 1

int main(void) {
#if TEST_FRAMEWORK
    return TestMain::StartTests();
#endif
//    auto& app = BoogieWoogieApp::GetInstance();
//    app.SetupSimulation();
//    app.RunSimulation();
    return 0;
}