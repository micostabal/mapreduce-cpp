#pragma once

#include <vector>
#include <string>

namespace common::utils::string_utils {
    std::vector<std::string> split_words(const std::string &string);
    unsigned long hash_word(const std::string &s);
    int hash_word_mod(const std::string &s, int mod);
}