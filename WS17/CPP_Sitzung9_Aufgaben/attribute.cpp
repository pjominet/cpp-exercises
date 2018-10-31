#include <iostream>
#include <string.h>
using namespace std;

#include "attribute.h"

int AttributeToken::getAttributeList(char *input) {
    char buffer[100];
    int counter;
    enum state {
        zwischenTags, inNamen, erwarteAttributNamen, erwarteAttributWert,
        verarbeiteAttributWert
    };
    enum state state;

    for (counter = 0, state = inNamen, attributeCounter = 0; *input != '\0'; input++) {
        switch (*input) {
            case ' ':
                if (state == inNamen) {
                    state = erwarteAttributNamen;
                    *input = '\0';
                    counter = 0;
                } else if (state == verarbeiteAttributWert) {
                    buffer[counter] = *input;
                    counter++;
                }
                break;

            case '=':
                if (state == erwarteAttributNamen) {
                    state = erwarteAttributWert;
                    buffer[counter] = '\0';
                    attributeName[attributeCounter] = new char[counter + 1];
                    strcpy(attributeName[attributeCounter], buffer);
                    counter = 0;
                } else if (state == verarbeiteAttributWert) {
                    buffer[counter] = *input;
                    counter++;
                } else cout << "Fehlerhaftes Zeichen! '='" << endl;
                break;

            case '"':
                if (state == erwarteAttributWert) {
                    state = verarbeiteAttributWert;
                    counter = 0;
                } else if (state == verarbeiteAttributWert) {
                    state = erwarteAttributNamen;
                    buffer[counter] = '\0';
                    attributeValue[attributeCounter] = new char[counter + 1];
                    strcpy(attributeValue[attributeCounter], buffer);
                    counter = 0;
                    attributeCounter++;
                } else cout << "Fehlerhaftes Zeichen! '\"'" << endl;
                break;

            default:
                if (state >= erwarteAttributNamen) {
                    buffer[counter] = *input;
                    counter++;
                }
                break;
        }
    }

    return 1;
}
