//
// Created by Patrick Jominet on 19.01.17.
//

#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

#include "AttributeToken.h"

class Token {
private:
    string tokenName;
    string tokenContent;
    Token *tokenChild;
    Token *tokenSibling;
public:
    Token();

    string getTokenName() { return tokenName; }

    string getTokenContent() { return tokenContent; }

    void tokenToOut(int layer);

    void tokenLayerToOut(int layer);

    int parseXML(ifstream &xml);

    AttributeToken attributes;
};

enum class tagState {
    isStartTag,
    isEndTag
};

enum class xmlParserState {
    parsingTokenName,
    parsingTokenAttributes,
    noise
};
