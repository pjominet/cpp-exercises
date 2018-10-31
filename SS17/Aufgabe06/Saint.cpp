#ifndef AUFGABE06_FEST_H
#define AUFGABE06_FEST_H

#include <iostream>

using namespace std;

class Saint {
private:
    string name;
    int day;
    int month;
public:

    Saint(string &name, int day, int month) : name(name), day(day), month(month) {}

    const string &getName() const {
        return name;
    }

    int getDay() const {
        return day;
    }

    int getMonth() const {
        return month;
    }
};

#endif //AUFGABE06_FEST_H
