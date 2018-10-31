#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

typedef map<int, char>::reverse_iterator MapIterator;


// I/O Colors
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"

int toArabic(string romanNumber);
string toRoman(int arabicNumber);

int doMath(char operation, int n1, int n2);

int main() {

    string input;
    char operation;
    int number1, number2, result;
    bool run = true;


    while (run) {
        cout << "Bitte geben Sie eine römische Zahl ein: ";
        cin >> input;
        transform(input.begin(), input.end(), input.begin(), ::tolower);
        if (toArabic(input) != -1) {
            number1 = toArabic(input);
            cout << GREEN << input << " <=> " << number1 << RESET << endl;
        } else {
            transform(input.begin(), input.end(), input.begin(), ::toupper);
            cout << RED << "'" << input << "' ist keine korrekte römische Zahl!" << RESET << endl;
            break;
        }


        cout << "Bitte geben Sie noch eine römische Zahl ein: ";
        cin >> input;
        transform(input.begin(), input.end(), input.begin(), ::tolower);
        if (toArabic(input) != -1) {
            number2 = toArabic(input);
            cout << GREEN << input << " <=> " << number2 << RESET << endl;
        } else {
            transform(input.begin(), input.end(), input.begin(), ::toupper);
            cout << RED << "'" << input << "' ist keine korrekte römische Zahl!" << RESET << endl;
            break;
        }


        cout << "Was soll damit geschehen? (+ - * /): ";
        cin >> operation;

       result = doMath(operation, number1, number2);

        if (result != -1) {
            cout << "Ergebnis arabisch: " << BLUE << result << RESET << endl;

            char conversion = 'y';
            cout << "Das Ergebnis in eine römische Zahl umwandeln? (y/n): ";
            cin >> conversion;
            switch (conversion) {
                case 'y':
                    cout << "Ergebnis römisch: " << BLUE << toRoman(result) << RESET << endl;
                    break;
                case 'n':
                    cout << RED << "Schade :(" << RESET << endl;
                    break;
                default:
                    break;
            }

        } else cout << RED << "Ungültiges Ergebnis" << RESET << endl;

        // ask for rerun
        char answer = 'n';
        cout << YELLOW << "Rerun? (y/n): " << RESET;
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

int doMath (char operation, int n1, int n2) {
    int result;

    switch (operation) {
        case '+':
            result = n1 + n2;
            break;
        case '-':
            result = n1 - n2;
            break;
        case '*':
            result = n1 * n2;
            break;
        case '/':
            if (n2 != 0) result = n1 / n2;
            break;
        default:
            result = -1;
            cout << RED << "Ungültiger Parameter" << RESET << endl;
    }

    return result;
}

int toArabic(string romanNumber) {
    map<char, int> romanToArabicMap = {
            {'m', 1000},
            {'d', 500},
            {'c', 100},
            {'l', 50},
            {'x', 10},
            {'v', 5},
            {'i', 1}
    };
    int index = 0;
    int decimalArray[romanNumber.size()];
    int arabicNumber = 0;

    if (romanNumber == "0") return 0;

    vector<char> romanNumberArray(romanNumber.c_str(), romanNumber.c_str() + romanNumber.size());

    // convert roman to arabic
    for (char rn : romanNumberArray) {
        if (romanToArabicMap.find(rn) != romanToArabicMap.end()) {
            decimalArray[index] = romanToArabicMap.at(rn);
            index++;
        } else break;
    }

    // check if preceding decimal is smaller and calculate complete number
    for (int i = 0; i < romanNumber.size(); i++) {
        if (i != romanNumber.size() - 1 &&
            decimalArray[i + 1] != 1 &&
            decimalArray[i] < decimalArray[i + 1]) {

            arabicNumber += decimalArray[i + 1] - decimalArray[i];
            i++; // to skip next, already calculated value

        } else if (i != romanNumber.size() - 1 &&
                   i != romanNumber.size() - 2 &&
                   decimalArray[i + 2] != 1 &&
                   decimalArray[i] < decimalArray[i + 2]) {

            i = i + 2; //skip next '1' and calculated value
            arabicNumber = -1;

        } else if (i != romanNumber.size() - 1 &&
                   i != romanNumber.size() - 2 &&
                   i != romanNumber.size() - 3 &&
                   decimalArray[i + 3] != 1 &&
                   decimalArray[i] < decimalArray[i + 3]) {

            i = i + 3; //skip next two '1' and calculated value
            arabicNumber = -1;

        } else {
            arabicNumber += decimalArray[i];
        }
    }

    return arabicNumber;
}

string toRoman(int arabicNumber) {
    map<int, char> arabicToRomanMap = {
            {1000, 'm'},
            {500,  'd'},
            {100,  'c'},
            {50,   'l'},
            {10,   'x'},
            {5,    'v'},
            {1,    'i'}
    };
    vector<char> romanNumber;
    int index = 0;

    if (arabicNumber == 0) return "0";
    else if (arabicNumber < 0) return "Negative Zahlen können nich umgewandelt werden :(";
    else if (arabicNumber > 4000) return "Zahlen, die grösser als 4000 sind, machen keinen Sinn umzuwandeln :)";

    for (MapIterator i = arabicToRomanMap.rbegin(); i != arabicToRomanMap.rend(); i++) {
        while (arabicNumber >= i->first) {
            romanNumber.push_back(i->second);
            arabicNumber -= i->first;
            index++;
        }
    }

    return string(romanNumber.begin(), romanNumber.end());
}