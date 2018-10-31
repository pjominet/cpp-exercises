#include "attribute.h"
#include "tagset.h"

class Token {
public:
    Token();

    char *name() { return tokenName; }

    Token *child() { return tokenChild; }

    char *content() { return tokenContent; }

    void getToken(int layer);

    int setToken(ifstream &data, Tagset *tagset);

    AttributeToken att;
private:
    void cleanToken();

    void getTokenLayer(int layer);

    int fillToken(int mode);

    char tokenName[64];
    Token *tokenChild;
    Token *tokenSibling;
    char *tokenContent;
};

enum state {
    isStartTag, isEndTag
};
