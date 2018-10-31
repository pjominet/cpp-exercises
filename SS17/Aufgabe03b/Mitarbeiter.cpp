#include <string>
#include <iostream>
#include "Person.cpp"

using namespace std;

class Mitarbeiter : public Person {
private:
    unsigned int telefonnummer;
    string promotionsthema;
public:
    Mitarbeiter(unsigned int geburtsjahr, const string &nachname, const string &vorname, unsigned int telefonnummer,
                const string &promotionsthema) : Person(geburtsjahr, nachname, vorname) {
        this->telefonnummer = telefonnummer;
        this->promotionsthema = promotionsthema;
    }

    ~Mitarbeiter() = default;

    void to_out() override {
        cout  <<  nachname << " " << vorname  << ", Alter: " << getAge() << endl;
        cout  << "Promotionsthema: " << promotionsthema << endl  << "Tel.: " << telefonnummer << endl;
        cout << endl;
    }
};