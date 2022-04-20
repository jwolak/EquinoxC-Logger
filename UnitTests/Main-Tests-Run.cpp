#include <gtest/gtest.h>
#include "gmock/gmock.h"


#include "LoggerC-Console-Tests.cpp"

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
