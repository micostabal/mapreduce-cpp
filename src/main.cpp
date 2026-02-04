#include <iostream>
#include "mapreduce/utils/string_utils.h"

int main() {
    std::cout << "MapReduce C++ project" << std::endl;
    std::cout << "The sum " << mapreduce::utils::string_utils::add(4, 6) << std::endl;
    return 0;
}