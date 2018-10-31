//
// Created by shominees on 2.5.17.
//

#ifndef UTILITIES_IFSTREAM_UTIL_H
#define UTILITIES_IFSTREAM_UTIL_H

#include <vector>
#include <string>
#include <regex>
#include <iostream>
#include <fstream>

namespace ifstream_util {

    std::vector<std::string> match_pattern(std::ifstream &data, std::string pattern);

    std::string convert_to_string(std::ifstream &data);
};

#endif //UTILITIES_IFSTREAM_UTIL_H
