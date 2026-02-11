#include <iostream>
#include <string>
#include <vector>
#include <common/utils/string_utils.h>


int main() {
    
    std::vector<std::string> words = common::utils::string_utils::split_words("Jesus is King!");
    
    std::cout << "MapReduce Worker" << std::endl;
    return 0;
}