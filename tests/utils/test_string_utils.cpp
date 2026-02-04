#include <gtest/gtest.h>
#include "mapreduce/utils/string_utils.h"


TEST(StringUtilsTest, ToDeleteAddFunction) {
    EXPECT_EQ(mapreduce::utils::string_utils::add(1, 1), 2);
}