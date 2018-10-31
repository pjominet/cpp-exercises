#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

#include "token.h"

Token::Token() {
    *tokenName = '\0';
    tokenChild = NULL;
    tokenSibling = NULL;
    tokenContent = new char[1];
    *tokenContent = '\0';
}

int Token::setToken(ifstream &data, Tagset *tagset) {
    int counter;
    enum state state;
    char c;
    char buffer[100];
    Token *child;
    int childSet;

    cleanToken();

    for (counter = 0;;) {
        data.get(c);
        if (data.eof()) {
            if (*tokenName == '\0' && tokenChild == NULL && tokenContent == NULL)
                return fillToken(0);
            return fillToken(1);
        }
        switch (c) {
            case '<':
                data.get(c);
                if (c == '/') {
                    state = isEndTag;
                    if (counter != 0) {
                        buffer[counter] = '\0';
                        tokenContent = new char[counter + 1];
                        strcpy(tokenContent, buffer);
                    }
                } else {
                    data.putback(c);
                    if (*tokenName != '\0') {
                        data.putback('<');
                        if (tokenChild == NULL) {
                            tokenChild = new Token;
                            if (tokenChild->setToken(data, tagset) == 0) return fillToken(0);
                        } else {
                            for (child = tokenChild;; child = child->tokenSibling) {
                                if (child->tokenSibling == NULL) {
                                    child->tokenSibling = new Token;
                                    if (child->tokenSibling->setToken(data, tagset) == 0)
                                        return fillToken(0);
                                    break;
                                }
                            }
                        }
                    } else state = isStartTag;
                }
                counter = 0;
                break;
            case '>':
                buffer[counter] = '\0';
                if (state == isEndTag) {
                    if (strcmp(tokenName, buffer)) {
                        cout << "Fehlerhaftes End Tag" << endl;
                        cout << "Erhalten: '" << buffer << "'; erwartet: '"
                             << tokenName << "'" << endl;
                        return fillToken(0);
                    }
                    return fillToken(1);
                }
                if (state == isStartTag) {
                    att.getAttributeList(buffer);
                    if (tagset == NULL) childSet = -1;
                    else childSet = tagset->isLegal(buffer);
                    if (childSet < 0) {
                        cout << "Fehlerhaftes Start Tag: '" << buffer << "'" << endl;
                        return fillToken(0);
                    }
                    tagset = tagset->getChild(childSet);
                    strcpy(tokenName, buffer);
                }
                counter = 0;
                break;
            case '\n':
                break;
            default:
                buffer[counter] = c;
                counter++;
                break;
        }
    }
}

int Token::fillToken(int mode) {
    if (*tokenName == '\0')
        strcpy(tokenName, "Unbekanntes Element");
    if (tokenContent == NULL) {
        tokenContent = new char[1];
        *tokenContent = '\0';
    }

    return mode;
}

void Token::cleanToken() {
    *tokenName = '\0';
    if (tokenChild != NULL) {
        delete tokenChild;
        tokenChild = NULL;
    }
    if (tokenContent != NULL) {
        delete tokenContent;
        tokenContent = NULL;
    }
}

void Token::getToken(int layer) {
    Token *child;

    getTokenLayer(layer);
    cout << "Token: " << name() << " - " << content() << endl;
    if (att.getAttributeCounter() > 0) {
        for (int i = 0; i < att.getAttributeCounter(); i++) {
            getTokenLayer(layer);
            cout << "Attribut " << att.getAttributeNameByID(i) << " hat den Wert "
                 << att.getAttributeValueByID(i) << endl;
        }
    }
    if (tokenChild != NULL) tokenChild->getToken(layer + 1);
    if (tokenSibling != NULL) tokenSibling->getToken(layer);
}

void Token::getTokenLayer(int layer) {
    while (layer > 0) {
        cout << "| ";
        layer = layer - 1;
    }
}
