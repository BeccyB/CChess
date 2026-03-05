#include <gtest/gtest.h>
#include "controller/controller.h"

TEST(TestGame, BasicAssertions) {

    Controller c;

    EXPECT_EQ(c.add(1, 2), 3);
    EXPECT_EQ(c.divide(4, 2), 2);
}