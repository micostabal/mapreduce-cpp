#include <gtest/gtest.h>
#include "common/utils/string_utils.h"

TEST(StringUtilsTest, SplitWordsFirst) {
    auto words = common::utils::string_utils::split_words("hello world from mapreduce");
    ASSERT_EQ(words.size(), 4);
    EXPECT_EQ(words[0], "hello");
    EXPECT_EQ(words[1], "world");
    EXPECT_EQ(words[2], "from");
    EXPECT_EQ(words[3], "mapreduce");
}

TEST(StringUtilsTest, HashWordTest) {
    int hash_mary = common::utils::string_utils::hash_word("Mary");
    int hash_paul = common::utils::string_utils::hash_word("Paul");
    
    std::cout << "Hash Mary: " << hash_mary << std::endl;
    std::cout << "Hash Paul: " << hash_paul << std::endl;

    ASSERT_NE(hash_mary, hash_paul);
}