#include <common/utils/string_utils.h>
#include <sstream>

namespace common::utils::string_utils {
    std::vector<std::string> split_words(const std::string &input) {
        
        std::istringstream iis(input);
        std::vector<std::string> words;
        std::string word;

        while (iis >> word) {
            words.push_back(word);
        }
        
        return words;
    }

    unsigned long hash_word(const std::string &s) {
        unsigned long hash = 5381;
        for (unsigned char c : s) {
            hash = ((hash << 5) + hash) + c;
        }
        return hash;
    }

    int hash_word_mod(const std::string &s, int bins) {
        return hash_word(s) % bins;
    }
}