//
// Created by shominees on 2.5.17.
//

#ifndef UTILITIES_STRING_UTIL_H
#define UTILITIES_STRING_UTIL_H

#include <vector>
#include <string>
#include <sstream>
#include <regex>
#include <iostream>
#include <algorithm>
#include <functional>
#include <cctype>
#include <locale>

namespace string_util {

    std::string ucfirst(std::string value);

    std::vector<std::string> split_by_delimiter(std::string &toSplit, char delimiter);

    std::string split_after_delimiter(std::string &str, char delimiter);

    std::string split_before_delimiter(std::string &str, char delimiter);

    std::vector<std::string> match_pattern(std::string &str, std::string pattern);

    std::vector<std::string> split_by_pattern(std::string &toSplit, std::string pattern);

    void trim_head(std::string &str);

    std::string ctrim_head(std::string value);

    void trim_tail(std::string &str);

    std::string ctrim_tail(std::string value);

    void trim(std::string &str);

    std::string ctrim(std::string value);
};

#endif //UTILITIES_STRING_UTIL_H
