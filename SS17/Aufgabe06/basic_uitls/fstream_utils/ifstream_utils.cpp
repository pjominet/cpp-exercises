//
// Created by shominees on 2.5.17.
//

#include "ifstream_utils.h"

namespace ifstream_util {

    /**
     * read an input stream line by line, match a given pattern to it and return all matches
     * @param data, the input file from which data will be read
     * @param pattern, the regex pattern as string
     * @return {vector} of strings with all tokens found by the match
     */
    std::vector<std::string> match_pattern(std::ifstream &data, std::string pattern) {
        std::vector<std::string> tokenList;

        for (std::string line; getline(data, line);) {
            try {
                std::regex regex_from(pattern);
                std::smatch match;
                if (regex_search(line, match, regex_from) && match.size() > 1) {
                    for (unsigned int i = 1; i < match.size(); i++) {
                        tokenList.push_back(match.str(i));
                    }
                } else {
                    std::cout << "No match" << std::endl;
                }
            } catch (std::regex_error &e) {
                std::cout << "Syntax error in the regular expression" << std::endl;
            }
        }
        return tokenList;
    }

    /**
     * Cast an input stream to a one line string and remove all whitespace noise in the process
     * @param data, the input file from which data will be read
     * @return {string} as one line from file data
     */
    std::string convert_to_string(std::ifstream &data) {
        std::string str, temp;

        while (std::getline(data, temp)) {
            // remove whitespace noise
            temp = std::regex_replace(temp, std::regex("^\\s+"), "");
            str.append(temp);
        }
        return str;
    }
}