#include <string>
#include <iostream>
#include "Person.cpp"

using namespace std;

class Professor : public Person {
private:
    unsigned int telefonnummer;
    string institut;
public:
    Professor(unsigned int geburtsjahr, const string &nachname, const string &vorname, unsigned int telefonnummer,
              const string &institut) : Person(geburtsjahr, nachname, vorname) {
        this->telefonnummer = telefonnummer;
        this->institut = institut;
    }

    ~Professor() = default;

    void to_out() override {
        cout  <<  nachname << " " << vorname  << ", Alter: " << getAge() << endl;
        cout << "Institut: " << institut << endl  << "Tel.: " << telefonnummer << endl;
        cout << endl;
    }
};