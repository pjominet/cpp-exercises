#include <iostream>
#include <fstream>
using namespace std;

#include "token.h"

int main() {
    char *elemente1[1] = {"kurs"};
    char *elemente2[1] = {"person"};
    char *elemente3[2] = {"vorname", "famname"};

    ifstream finput;
    Token *token;
    Tagset *tagset, *child;

    tagset = new Tagset(1, elemente1);
    tagset->addTagset(1, 0, elemente2);
    child = tagset->getChild(0);
    child->addTagset(2, 0, elemente3);

    // adeptable
    const std::string PATHTOFILES = "/home/shominees/Development/HKI/CPP/data/";

    finput.open(PATHTOFILES + "tags.txt");
    // tagset->readTagset(finput, )
    finput.close();

    finput.open(PATHTOFILES + "data.xml");

    token = new Token;

    if (token->setToken(finput, tagset) != 0) token->getToken(1);
    finput.close();

    return 0;
}
