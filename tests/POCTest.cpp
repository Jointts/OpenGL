#include <gtest/gtest.h>

const char *actualValTrue  = "hello gtest";
const char *expectVal      = "hello gtest";

TEST(StrCompare, CStrEqual) {
    EXPECT_STREQ(expectVal, actualValTrue);
}