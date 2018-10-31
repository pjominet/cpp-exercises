#include <iostream>
#include "CharacterChain.cpp"

using namespace std;

int main() {
    CharacterChain str1, str2, str3;
    string buffer;

    cout << "Please enter a string: "; cin >> buffer;
    str1 = CharacterChain(buffer.c_str());
    cout << "Please enter a second string: "; cin >> buffer;
    str2 = CharacterChain(buffer.c_str());

    str3 = str1 + str2;

    cout << str1 << " + " << str2 << " = " << str3 << endl;

    return 0;
}