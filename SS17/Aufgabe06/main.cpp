#include <iostream>

using namespace std;

#include "SaintsCalender.cpp"
#include "basic_uitls/string_utils/string_utils.h"

int main() {

    ifstream input;
    SaintsCalender calender;
    Saint *saint = nullptr;
    bool run = true;
    char command = '*';
    string search = "";

    input.open("saints.txt");
    while(!input.eof()) {
        calender.loadCalender(input);
    }
    input.close();

    while (run) {
        cout << "Choose activity:" << endl <<
             " n - search saint by name" << endl <<
             " z - search saint by date" << endl <<
             " q - quit program" << endl;
        cin >> command;
        switch (command) {
            case 'n':
                cout << "Please enter the name of a saint: ";
                cin >> search;
                saint = calender.getSaint_byName(search);
                if (saint != nullptr)
                    cout << saint->getName() << " is being celebrated on " << saint->getDay() << "." << saint->getMonth() << endl;
                else cout << "Unknown saint!" << endl;
                delete saint;
                break;
            case 'z':
                cout << "Please enter a day and a month separated by a period:";
                cin >> search;
                saint = calender.getSaint_byDate(stoi(string_util::split_before_delimiter(search, '.')),
                                                 stoi(string_util::split_after_delimiter(search, '.')));
                if (saint != nullptr)
                    cout << "On this date, " << saint->getName() << " is being celebrated" << endl;
                else cout << "No entry for this date!" << endl;
                delete saint;
                break;
            case 'q':
                run = false;
                break;
            default:
                cout << "\'" << command << "\' Unknown command" << endl;
                break;
        }
    }
    return EXIT_SUCCESS;
}