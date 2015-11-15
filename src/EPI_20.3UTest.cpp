#include <gtest/gtest.h>
#include "EPI_20.3.hpp"
#include <iostream>
#include <sstream>

TEST(EPI_20_3, Print100) {
    std::ostringstream ss_output;
    printThreaded(ss_output);
    std::ostringstream ss_expected;
    for (int i = 0; i < 100; i++) {
        ss_expected << i << ", ";
    }

    ASSERT_EQ(ss_output.str(), ss_expected.str());

}
