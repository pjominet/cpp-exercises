//
// Created by shominees on 2.5.17.
//

#include "string_utils.h"

namespace string_util {

    /**
     * Uppercase first letter and lowercase rest of string
     * @param value, a string to be manipulated
     * @return {string} copy of value with uppercase first letter
     */
    std::string ucfirst(std::string value) {
        if (!value.empty()) {
            auto i = value.begin();
            *i = (unsigned char) std::toupper(*i++);
            std::transform(i, value.end(), i, ::tolower);
        }
        return value;
    }

    /**
     * Splits a given string at every occurrence of a given delimiter and returns all substrings obtained this way
     * @param reference, the string that is to be split
     * @param delimiter, the character delimiting the substring of the reference string
     * @return {vector} of strings containing all substrings after the splitting
     */
    std::vector<std::string> split_by_delimiter(std::string &reference, char delimiter) {
        std::vector<std::string> tokenList;
        std::string token;

        std::stringstream ss(reference);
        while (getline(ss, token, delimiter)) {
            tokenList.push_back(token);
        }
        return tokenList;
    }

    /**
     * Splits a string at the first occurrence of a given delimiter and return the remaining tail
     * @param reference, a string by address that is to be split
     * @param delimiter, a character delimiting the substrings of the reference string
     * @return {string} tail after the delimiter
     */
    std::string split_after_delimiter(std::string &reference, char delimiter) {
        return reference.substr(reference.find(delimiter) + 1);
    }

    /**
     * Splits a string at the first occurrence of a given delimiter and return the remaining head
     * @param reference, a string by address that is to be split
     * @param delimiter, a character delimiter the tokens of the string in question
     * @return {string} head before the delimiter
     */
    std::string split_before_delimiter(std::string &reference, char delimiter) {
        return reference.substr(0, reference.find(delimiter));
    }

    /**
     * finds all substrings in a reference string matching a given pattern
     * @param reference, a string by address on which the pattern should match
     * @param pattern, a regex pattern as string
     * @return {vector} of strings with all substrings found by the match (can be empty if nothing was found!)
     */
    std::vector<std::string> match_pattern(std::string &reference, std::string pattern) {
        std::vector<std::string> tokenList;

        try {
            std::regex regex_pattern(pattern);
            std::smatch match;
            if (regex_search(reference, match, regex_pattern) && match.size() > 1) {
                for (unsigned int i = 1; i < match.size(); i++) {
                    tokenList.push_back(match.str(i));
                }
            } else {
                std::cout << "No match" << std::endl;
            }
        } catch (std::regex_error &re) {
            std::cout << "Syntax error in the regular expression" << std::endl;
        }
        return tokenList;
    }

    /**
     * Splits a reference string by a given pattern and returns all remaining substrings
     * @param reference, a string by address that is to be split
     * @param pattern, a regex pattern as string
     * @return {vector} of strings with all tokens found by the match (can be empty if nothing was found!)
     */
    std::vector<std::string> split_by_pattern(std::string &reference, std::string pattern) {
        std::vector<std::string> tokenList;

        try {
            std::regex regex_pattern(pattern);
            // custom iterator with given pattern
            auto words_begin =
                    std::sregex_iterator(reference.begin(), reference.end(), regex_pattern);
            auto words_end = std::sregex_iterator();
            for (std::sregex_iterator i = words_begin; i != words_end; ++i) {
                std::smatch match = *i;
                std::string match_str = match.str();
                tokenList.push_back(match_str);
            }
        } catch (std::regex_error &re) {
            std::cout << "Syntax error in the regular expression" << std::endl;
        }
        return tokenList;
    }

    /**
     * trims leading whitespace of a given string
     * @param reference, a string by address that is to be trimmed
     */
    void trim_head(std::string &reference) {
        reference.erase(reference.begin(),
                        std::find_if(reference.begin(), reference.end(),
                                     std::not1(std::ptr_fun<int, int>(std::isspace))));
    }

    /**
     * trims leading whitespace of a given string and returns a copy of it
     * @param value, a string by value that is to be trimmed
     * @return {string} manipulated copy of value
     */
    std::string ctrim_head(std::string value) {
        trim_head(value);
        return value;
    }

    /**
     * trims trailing whitespace of a given string
     * @param reference, a string by address that is to be trimmed
     */
    void trim_tail(std::string &reference) {
        reference.erase(std::find_if(reference.rbegin(), reference.rend(),
                                     std::not1(std::ptr_fun<int, int>(std::isspace))).base(),
                        reference.end());
    }

    /**
     * trims trailing whitespace of a given string and returns a copy of it
     * @param value, a string by value that is to be trimmed
     * @return {string} manipulated copy of value
     */
    std::string ctrim_tail(std::string value) {
        trim_tail(value);
        return value;
    }

    /**
     * trims leading and trailing whitespace of a given string
     * @param reference, a string by address that is to be trimmed
     */
    void trim(std::string &reference) {
        trim_head(reference);
        trim_tail(reference);
    }

    /**
     * trims leading and trailing whitespace of a given string and returns a copy of it
     * @param value, a string by value that is to be trimmed
     * @return {string} manipulated copy of value
     */
    std::string ctrim(std::string value) {
        trim(value);
        return value;
    }
}