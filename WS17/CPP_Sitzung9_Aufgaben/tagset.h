class Tagset {
private:
    int tagCounter;
    char **tagNames;
    Tagset **child;

public:
    Tagset(int nTags, char **tags);

    void addTagset(int nTags, int slot, char **tags);

    int isLegal(char *name);

    Tagset *getChild(int slot) { return child[slot]; }

    int readTagset(ifstream &data, char **tags);
};