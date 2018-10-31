#include <string.h>

class AttributeToken {
private:
    int attributeCounter;
    char *attributeName[10];
    char *attributeValue[10];
public:
    int getAttributeList(char *input);

    char *getAttributeNameByID(int id) { return attributeName[id]; }

    char *getAttributeValueByID(int id) { return attributeValue[id]; }

    int getAttributeCounter() { return attributeCounter; }
};
