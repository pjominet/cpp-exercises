#include <iostream>
#include <fstream>

#include "Person.h"

Person::Person(std::string fn, std::string ln, std::string bd) {
    firstName = fn;
    lastName = ln;
    birthdate = bd;
}

void Person::setBirthdate(const std::string &birthdate) {
    Person::birthdate = birthdate;
}

const std::string &Person::getFirstName() const {
    return firstName;
}

const std::string &Person::getLastName() const {
    return lastName;
}

const std::string &Person::getBirthdate() const {
    return birthdate;
}