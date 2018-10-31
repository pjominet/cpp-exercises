#include <iostream>
#include <fstream>
#include <regex>

#include "Person.h"

int main() {
    std::ifstream finput;

    /* add path to data here */
    const std::string PATHTOFILES = "/home/shominees/Development/HKI/CPP/data/";
    void createPersonFromFile(std::ifstream &data);

    finput.open(PATHTOFILES + "w7Data.txt");

    createPersonFromFile(finput);

    finput.close();
}

void createPersonFromFile(std::ifstream &data) {

    for (std::string line; std::getline(data, line);) {
        try {
            std::regex pattern(
                    "Name\\s*:\\s*([a-zA-z]+),\\s*([a-zA-Z]+)\\s*\\.\\s*Geburtsdatum\\s*:\\s*(\\d+)\\s*\\.\\s*(\\d+)\\s*\\.\\s*(\\d+)");
            std::smatch match;
            if (std::regex_search(line, match, pattern) && match.size() > 1) {
                Person person = Person(match.str(2), match.str(1), match.str(3)+"."+match.str(4)+"."+match.str(5));
                std::cout << "Person: " << person.getFirstName() << " " << person.getLastName() << ", born " << person.getBirthdate() << std::endl;
            } else {
                std::cout << "No match" << std::endl;
            }
        } catch (std::regex_error &e) {
            std::cout << "Syntax error in the regular expression" << std::endl;
        }
    }
}