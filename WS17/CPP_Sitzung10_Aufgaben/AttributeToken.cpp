//
// Created by Patrick Jominet on 19.01.17.
//

#include "IOColors/definitions.h"
#include "AttributeToken.h"

int AttributeToken::parseAttributes(char* data) {
    string buffer;

    attributeParserState state;
    for (state = attributeParserState::parsingAttributeName, attributeCount = 0; *data != '\0'; data = data + 1) {
        switch (*data) {
            case ' ':
                if (state == attributeParserState::parsingAttributeName) {
                    state = attributeParserState::expectingAttributeName;
                    *data = '\0';
                } else if (state == attributeParserState::parsingAttributeValue) {
                    buffer += *data;
                }
                break;
            case '=':
                if (state == attributeParserState::expectingAttributeName) {
                    state = attributeParserState::expectingAttributeValue;
                    buffer = "";
                    attributeNames.push_back(buffer);
                } else if (state == attributeParserState::parsingAttributeValue) {
                    buffer += *data;
                } else cout << RED << "Illegal character! '='" << RESET << endl;
                break;
            case '"':
                if (state == attributeParserState::expectingAttributeValue) {
                    state = attributeParserState::parsingAttributeValue;
                } else if (state == attributeParserState::parsingAttributeValue) {
                    state = attributeParserState::expectingAttributeName;
                    buffer = "";
                    attributeValues.push_back(buffer);
                    attributeCount++;
                } else cout << RED << "Illegal Character! '\"'" << RESET << endl;
                break;
            default:
                if (state >= attributeParserState::expectingAttributeName) {
                    buffer += *data;
                }
                break;
        }
    }
    return 0;
}