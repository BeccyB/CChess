#include <gtest/gtest.h>

TEST(TestGame, BasicAssertions) {

    // Expect two strings not to be equal.
    EXPECT_STRNE("hello", "world");
    // Expect equality.
    EXPECT_EQ(7 * 6, 42);
    // Expect that boolean is true.
    EXPECT_TRUE(true);
    // Expect that a pointer is not null.
    int* ptr = new int(5);
    EXPECT_NE(ptr, nullptr);
    delete ptr;  // Clean up the allocated memory.

}