//
// Created by Patrick Jominet on 19.01.17.
//

#include "IOColors/definitions.h"
#include "Token.h"

Token::Token() {
    tokenName = "";
    tokenContent = "";
    tokenChild = NULL;
    tokenSibling = NULL;
}

int Token::parseXML(ifstream &xml) {
    char current;
    string buffer;
    Token *child;

    tagState state;
    xmlParserState parserState = xmlParserState::noise;
    for (xml.get(current); !xml.eof(); xml.get(current)) {
        switch (current) {
            case '<':
                parserState = xmlParserState::parsingTokenName;
                xml.get(current); //get next after current
                if (current == '/') {
                    state = tagState::isEndTag;
                    if (buffer != "") {
                        tokenContent = buffer;
                        buffer = "";
                    }
                } else {
                    xml.putback(current); //set next back to current
                    state = tagState::isStartTag;
                    /*if (tokenName != "") {
                        xml.putback('<');
                        if (tokenChild == NULL) {
                            tokenChild = new Token;
                            tokenChild->parseXML(xml);
                        } else {
                            for (child = tokenChild;; child = child->tokenSibling) {
                                if (child->tokenSibling == NULL) {
                                    child->tokenSibling = new Token;
                                    child->tokenSibling->parseXML(xml);
                                    break;
                                }
                            }
                        }
                    }*/
                }
                break;
            case '>':
                if (state == tagState::isEndTag) break;
                if (state == tagState::isStartTag) {
                    if(parserState == xmlParserState::parsingTokenAttributes) {
                        char * attributeList = new char[buffer.size() + 1];
                        copy(buffer.begin(), buffer.end(), attributeList);
                        attributeList[buffer.size()] = '\0';
                        attributes.parseAttributes(attributeList);
                        delete[] attributeList;
                    }
                }
                buffer = "";
                break;
            case ' ':
                if (parserState == xmlParserState::parsingTokenName) {
                    tokenName = buffer;
                    parserState = xmlParserState::parsingTokenAttributes;
                }
                break;
            case '\n':
                break;
            default:
                buffer += current;
                break;
        }
    }
    return 0;
}

void Token::tokenToOut(int layer) {
    tokenLayerToOut(layer);
    cout << "Token: "
         << BLUE << getTokenName() << RESET;
    if(getTokenContent() != "") {
        cout << " - "
             << CYAN << getTokenContent() << RESET
             << endl;
    } else cout << endl;
    if (attributes.getAttributeCount() > 0) {
        for (unsigned  int i = 0; i < attributes.getAttributeCount(); i++) {
            tokenLayerToOut(layer);
            cout << "Attribute "
                 << YELLOW << attributes.getAttributeName(i) << RESET
                 << " has value "
                 << GREEN << attributes.getAttributeValue(i) << RESET
                 << endl;
        }
    }
    if (tokenChild != NULL) tokenChild->tokenToOut(layer + 1);
    if (tokenSibling != NULL) tokenSibling->tokenToOut(layer);
}

void Token::tokenLayerToOut(int layer) {
    while (layer > 0) {
        cout << "| ";
        layer--;
    }
}