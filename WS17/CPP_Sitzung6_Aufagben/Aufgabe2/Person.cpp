#include "Person.h"

void Person::setName(std::string name) {
    if (name == "Paul")
        this->name = name;
    else return;

}

std::string Person::getName() {
    return this->name;
}