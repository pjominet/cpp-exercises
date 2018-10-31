//
// Created by Patrick Jominet on 25.01.17.
//

#include <iostream>
#include <fstream>
#include <string.h>
#include <vector>

using namespace std;

class Element {
private:
    unsigned int count;
    string name;
    vector<string> tags;
    vector<string> validTags;
public:
    Element();

    unsigned int getCount() { return count; }

    string getName() { return name; }

    string getTagAtIndex(unsigned int index) { return tags.at(index); }

    int parseDTD(ifstream &dtd);

    bool isElementValid(char *elementName, Element *currentElement);

    void elementToOut();
};


enum class dtdParserState {
    directive, element, dependency, noise
};

