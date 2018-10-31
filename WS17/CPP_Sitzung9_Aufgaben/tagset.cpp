#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

#include "tagset.h"

int Tagset::isLegal(
        char *name) {
    for (int i = 0; i < tagCounter; i++)
        if (!strcmp(name, tagNames[i])) return i;

    return -1;
}

Tagset::Tagset(int nTags, char **tags) {
    int index;
    tagCounter = nTags;
    tagNames = new char *[nTags];
    for (index = 0; index < nTags; index++) {
        tagNames[index] = new char[64];
        strcpy(tagNames[index], tags[index]);
    }
    child = new Tagset *[nTags];
    for (index = 0; index < nTags; index++)
        child[index] = NULL;
}

void Tagset::addTagset(int nTags, int slot, char **tags) {
    child[slot] = new Tagset(nTags, tags);
}

int Tagset::readTagset(ifstream &data, char **tags) {
    int counter;
    char c;
    char buffer[100];

    for (counter = 0;;) {
        data.get(c);
        if (data.eof()) {
            if (tagNames != NULL)
                return 0;
            return -1;
        }
        switch (c) {
            case '<':
                data.putback(c);
                break;
            case '>':
                buffer[counter] = '\0';
                counter = 0;
                break;
            case ' ':
                if (c == '!') {
                    if (counter != 0) {
                        buffer[counter] = '\0';
                        tagNames[counter] = new char[counter + 1];
                        strcpy(tagNames[counter], tags[counter]);
                    }
                }
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