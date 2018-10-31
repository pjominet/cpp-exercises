#ifndef AUFGABE06_KALENDER_H
#define AUFGABE06_KALENDER_H

#include <vector>
#include <fstream>

#include "Saint.cpp"
#include "basic_uitls/fstream_utils/ifstream_utils.h"

class SaintsCalender {
private:
    vector<Saint *> saintsCalender;
public:
    SaintsCalender() = default;

    void loadCalender(ifstream &data) {
        vector<string> raw = ifstream_util::match_pattern(data, "(.+)\\/(\\d+)\\.(\\d+)");
        for (unsigned int i = 0; i < raw.size() - 1; i += 3) {
            string name = raw[i];
            int day = stoi(raw[i + 1]);
            int month = stoi(raw[i + 2]);
            saintsCalender.push_back(new Saint(name, day, month));
        }
    }

    Saint *getSaint_byName(string &name) {
        Saint *result = nullptr;
        for (auto saint : saintsCalender) {
            if ((saint->getName().find(name)) != std::string::npos) {
                result = saint;
                break;
            }
        }
        return result;
    }

    Saint *getSaint_byDate(int day, int month) {
        Saint *result = nullptr;
        for (auto saint : saintsCalender) {
            if (saint->getDay() == day && saint->getMonth() == month) {
                result = saint;
                break;
            }
        }
        return result;
    }
};

#endif //AUFGABE06_KALENDER_H
