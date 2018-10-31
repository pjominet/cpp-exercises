//
// Created by Patrick Jominet on 19.01.17.
//

#include <iostream>
#include <string.h>
#include <vector>

using namespace std;

class AttributeToken {
private:
    unsigned  int attributeCount;
    vector<string> attributeNames;
    vector<string> attributeValues;
public:
    string getAttributeName(unsigned int index) { return attributeNames.at(index); }

    string getAttributeValue(unsigned int index) { return attributeValues.at(index); }

    int getAttributeCount() { return attributeCount; }

    int parseAttributes(char* data);
};

enum class attributeParserState {
    parsingAttributeName,
    expectingAttributeName,
    parsingAttributeValue,
    expectingAttributeValue,
    noise
};
