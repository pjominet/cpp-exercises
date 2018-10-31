#include <string>
#include <iostream>
#include "Person.cpp"

using namespace std;

class Student : public Person {
private:
    string studiengang;
    unsigned int matrikelnummer;
public:
    Student(unsigned int geburtsjahr, const string &nachname, const string &vorname, const string &studiengang,
            unsigned int matrikelnummer) : Person(geburtsjahr, nachname, vorname) {
        this->studiengang = studiengang;
        this->matrikelnummer = matrikelnummer;
    }

    ~Student() = default;

    void to_out() override {
        cout <<  nachname << " " << vorname  << ", Alter: " << getAge() << endl;
        cout << "Studiengang: " << studiengang  << endl << "Mat. Nr.: " << matrikelnummer  << endl;
        cout << endl;
    }
};