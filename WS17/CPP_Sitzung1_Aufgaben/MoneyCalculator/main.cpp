#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    // conversion rates:
    int toPound = 1;
    int toSchilling = toPound * 20;
    int toPfennig = toSchilling * 12;

    float inputPound = 0;
    float inputSchilling = 0;
    float sumInPound = 0;
    float sum = 0;

    int convert;
    char answer = 'n';
    bool run = true;
    bool inputCheck = true;

    while (run) {
        cout << "Please enter a value in pound:" << endl;
        cin >> inputPound;
        cout << "Please enter a value in schilling:";
        cin >> inputSchilling;
        sumInPound = (inputPound + inputSchilling / toSchilling);
        sum = sumInPound * toPfennig;
        cout << "Total in pfennig: " << setprecision(2) << fixed << sum << endl;

        while (inputCheck) {
            cout << "choose currency to convert to:" << endl
                 << "1 = pound" << endl
                 << "2 = schilling" << endl
                 << "3 = pfennig" << endl;
            cin >> convert;

            switch (convert) {
                case 1:
                    cout << "Sum in pound: " << sumInPound * toPound  << endl;
                    inputCheck = false;
                    break;
                case 2:
                    cout << "Sum in schilling: " << sumInPound * toSchilling << endl;
                    inputCheck = false;
                    break;
                case 3:
                    cout << "Sum in pfennig: " << sumInPound * toPfennig << endl;
                    inputCheck = false;
                    break;
                default:
                    cout << "Please enter a valid option" << endl;
                    inputCheck = true;
            }
        }

        cout << "Rerun? (y/n): ";
        cin >> answer;

        switch (answer) {
            case 'y':
                run = true;
                break;
            case 'n':
                run = false;
                break;
            default:
                run = false;
        }
    }

    return 0;
}