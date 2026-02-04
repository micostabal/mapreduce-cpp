#pragma once

#include <vector>
#include <string>

namespace mapreduce::utils::string_utils {
    std::vector<std::string> split_words(const std::string &string);
}