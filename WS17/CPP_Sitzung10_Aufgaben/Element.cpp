//
// Created by Patrick Jominet on 25.01.17.
//

#include "IOColors/definitions.h"
#include "Element.h"

Element::Element() {
    count = 0;
    name = "";
}

int Element::parseDTD(ifstream &dtd) {
    char current, last = '\0';
    string buffer;

    dtdParserState dtdState = dtdParserState::noise;
    for (dtd.get(current); !dtd.eof(); dtd.get(current)) {
        switch (current) {
            case '<':
                dtdState = dtdParserState::directive;
                break;
            case '>':
                if (dtdState != dtdParserState::noise) {
                    if (last != ' ') {
                        tags.push_back(buffer);
                        validTags.push_back(buffer);
                        count++;
                        buffer = "";
                    }
                    elementToOut();
                }
                dtdState = dtdParserState::noise;
                break;
            case ' ':
                if (last == ' ') continue; //break out of case, but continue loop
                switch (dtdState) {
                    case dtdParserState::directive:
                        if (buffer != "!ELEMENT") {
                            cout << RED << "Unknown directive!" << RESET << endl;
                            dtdState = dtdParserState::noise;
                        } else {
                            dtdState = dtdParserState::element;
                            buffer += '\0';
                        }
                        break;
                    case dtdParserState::element:
                        name = buffer;
                        validTags.push_back(buffer);
                        dtdState = dtdParserState::dependency;
                        break;
                    case dtdParserState::dependency:
                        tags.push_back(buffer);
                        validTags.push_back(buffer);
                        count++;
                        break;
                    default:
                        break;
                }
                break;
            default:
                if (dtdState != dtdParserState::noise) buffer += current;
                break;
        }
        last = current;
    }
    return 0;
}

bool Element::isElementValid(char *elementName, Element *currentElement) {
    for (unsigned int i = 0; i < currentElement->count; i++) {
        if (currentElement->validTags.at(i) == elementName) return true;
    }
    return false;
}

void Element::elementToOut() {
    cout << "Element "
         << BLUE << getName() << RESET
         << " containing Tags: ";
    for (unsigned int i = 0; i < getCount(); i++) {
        if (i > 0)
            cout << RESET << ", ";
        cout << YELLOW << getTagAtIndex(i) << RESET;
    }
    cout << "." << RESET << endl;
}