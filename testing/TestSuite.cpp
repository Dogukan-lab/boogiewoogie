//
// Created by doguk on 10/27/2024.
//

#include "TestSuite.hpp"
#include "TestLogger.hpp"
#include "gtest/gtest.h"

int TestSuite::StartTests() {
    ::testing::InitGoogleTest();
    ::testing::TestEventListeners& listeners = ::testing::UnitTest::GetInstance()->listeners();

    listeners.Append(new TestLogger);
    int result = RUN_ALL_TESTS();

    return result;
}