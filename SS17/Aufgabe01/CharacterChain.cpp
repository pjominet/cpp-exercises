#include <iostream>
#include <cstring>

using namespace std;

class CharacterChain {
private:
    int length;
    char *text;
public:

    /** default constructor */
    CharacterChain() {
        length = 100;
        text = new char(length);
    }

    /** explicit length constructor */
    explicit CharacterChain(int length) {
        this->length = length + 1;
        text = new char(this->length);
    }

    /** explicit char * constructor */
    explicit CharacterChain(const char *text) {
        this->length = strlen(text);
        this->text = new char(length + 1);
        strcpy(this->text, text);
    }

    /** Rule of Five
     ** https://en.wikipedia.org/wiki/Rule_of_three_%28C++_programming%29
     **/

    /** copy constructor */
    CharacterChain(const CharacterChain &cc) {
        this->length = strlen(cc.text);
        text = cc.text;
    }

    /** move constructor */
    CharacterChain(CharacterChain &&other) noexcept {
        other.length = 0;
        other.text = nullptr;
    }

    /** destructor */
    ~CharacterChain() noexcept {
        delete &length;
        delete text;
    }

    /** copy assignment operator */
    CharacterChain &operator=(const CharacterChain &cc) {
        strcpy(text, cc.text);
        return *this;
    }

    /** move assignment operator */
    CharacterChain &operator=(CharacterChain &&other) noexcept {
        delete text;
        text = other.text;
        other.text = nullptr;
        return *this;
    }

    /** End Rule of Five **/

    friend istream &operator>>(istream &in, const CharacterChain &cc) {
        in >> cc.text;
        return in;
    }

    friend ostream &operator<<(ostream &out, const CharacterChain &cc) {
        out << cc.text;
        return out;
    }

    friend CharacterChain operator+(CharacterChain &cc, CharacterChain &other) {
        CharacterChain cc_cat;
        strcpy(cc_cat.text, cc.text);
        strcat(cc_cat.text, other.text);
        return cc_cat;
    }

    // TODO: fix ambiguous overload
//    CharacterChain operator+ (const CharacterChain &cc) {
//        strcat(text, cc.text);
//        return *this;
//    }
};
