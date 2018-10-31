#include <string>
#include <iostream>

using namespace std;
extern unsigned int YEAR;

#ifndef PERSON_CPP
#define PERSON_CPP

class Person {
protected:
    unsigned int geburtsjahr;
    string nachname;
    string vorname;
public:
    Person(unsigned int geburtsjahr, const string &nachname, const string &vorname) {
        this->geburtsjahr = geburtsjahr;
        this->nachname = nachname;
        this->vorname = vorname;
    }

    virtual ~Person() = default;

    unsigned int getAge() {
        return YEAR - geburtsjahr;
    }

    virtual void to_out() {
        cout  <<  nachname << " " << vorname  << ", Alter: " << getAge() << endl;
        cout << endl;
    }

};

#endif
