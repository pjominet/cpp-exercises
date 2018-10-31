#include <iostream>

using namespace std;

#include "person1.h"

int main() {
    ClPerson person;
    char sprache;

    cout << "Wählen Sie Ihre Sprache:" << endl;
    cout << "e = English" << endl;
    cout << "d = deutsch" << endl;
    cout << "   Ihre Wahl:";
    cin >> sprache;

    cout << "Sie kommen aus:" << endl;
    cout << "w = Westeuropa" << endl;
    cout << "a = Amerika" << endl;
    cout << "r = Rußland" << endl;
    cout << "o = Österreich" << endl;
    cout << "   Ihre Herkunft:";
    cin >> person.herkunft;

    switch (sprache) {
        case 'e':
            askEnglish(&person);
            break;
        case 'd':
            frageDeutsch(&person);
            break;
        default:
            cout << "I do not know your language / Maybe you know English?";
            askEnglish(&person);
            sprache = 'e';
            break;
    }

    switch (sprache) {
        case 'e':
            greetEnglish(&person);
            break;
        case 'd':
            gruesseDeutsch(&person);
            break;
    }
}
