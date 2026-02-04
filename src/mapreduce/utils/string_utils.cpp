#include "mapreduce/utils/string_utils.h"
#include <sstream>

namespace mapreduce::utils::string_utils {
    std::vector<std::string> split_words(const std::string &input) {
        
        std::istringstream iis(input);
        std::vector<std::string> words;
        std::string word;

        while (iis >> word) {
            words.push_back(word);
        }
        
        return words;
    }
}