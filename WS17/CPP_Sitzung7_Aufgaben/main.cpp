#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

std::vector<std::string> split_by_delimiter(std::string &reference, char delimiter);
std::string readData(std::ifstream input);

int main() {

    char c;
    char buffer[100];
    int index;
    std::string TagName;

    std::ifstream finput;

    finput.open("data.xml");
    for (index = 0;;) {
        finput.get(c);
        if (finput.eof()) break;
        switch (c) {
            case '<':
                break;
            case '>':
                if (index) {
                    buffer[index] = '\0';
                    if(buffer[0] == '/') {
                        buffer[0] = '\0';
                    }
                    else TagName = buffer;
                    index = 0;
                }
                break;
            case '\n':
                break;
            default:
                buffer[index] = c;
                index++;
                break;
        }
    }
    finput.close();
}

std::vector<std::string> split_by_delimiter(std::string &reference, char delimiter) {
    std::vector<std::string> tokenList;
    std::string token;

    std::stringstream ss(reference);
    while (getline(ss, token, delimiter)) {
        tokenList.push_back(token);
    }
    return tokenList;
}