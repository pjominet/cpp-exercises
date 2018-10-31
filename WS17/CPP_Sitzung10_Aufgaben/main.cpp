#include <iostream>
#include <fstream>

using namespace std;

#include "IOColors/definitions.h"
#include "Token.h"
#include "Element.h"

int main() {
    ifstream inputXML, inputDTD;
    string fileName;

    Token *token;
    Element *element;

    cout << "Specify DTD-File: " << endl;
    cin >> fileName;
    inputDTD.open(fileName);
    if(!inputDTD) {
        cout << RED << "No such file found!" << RESET << endl;
        return 1;
    } else {
        element = new Element();
        element->parseDTD(inputDTD);
    }
    inputDTD.close();

    cout << "Specify XML-File: " << endl;
    cin >> fileName;
    inputXML.open(fileName);
    if(!inputXML) {
        cout << RED << "No such file found!" << RESET << endl;
        return 1;
    } else {
        token = new Token();
        if (token->parseXML(inputXML) == 0) token->tokenToOut(1);
    }
    inputXML.close();

    return 0;
}