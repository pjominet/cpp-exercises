#include <iostream>

using namespace std;

// I/O Colors
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"

string answerGerman ();
string answerEnglish ();

int main() {

    string input = "";

    cout << "Please choose a language (en/de): ";
    cin >> input;

    if(input == "de") cout << GREEN << answerGerman() <<  RESET << endl;
    else if(input == "en") cout << GREEN << answerEnglish() << RESET << endl;
    else cout << RED << "Invalid input" << RESET << endl;

    return 0;
}

string answerGerman () {
    string name;

    cout << YELLOW << "Hallo! Wie ist ihr Name?" << RESET << endl;
    cin >> name;

    return "Willkommen bei C++, " + name + "!";

}

string answerEnglish () {
    string name;

    cout << YELLOW << "Hello! What is your name?" << RESET << endl;
    cin >> name;

    return "Wellcome to C++, " + name + "!";

}