#include <FileReader.hpp>
#include <FileReaderFactory.hpp>
#include <TestSuite.hpp>
#include <gtest/gtest.h>

#include "BoogieWoogieApp.hpp"

#define TEST_FRAMEWORK 1

int main(void) {
#if TEST_FRAMEWORK
    return TestSuite::StartTests();
#endif
    // const auto reader = FileReaderFactory::CreateFileReader(R"(../assets/wrongfile.txt)");
    // auto [type, data] = reader->ReadContent();
    // auto& app = BoogieWoogieApp::GetInstance();
    // app.SetupSimulation();
    // app.RunSimulation();
    // return 0;
}