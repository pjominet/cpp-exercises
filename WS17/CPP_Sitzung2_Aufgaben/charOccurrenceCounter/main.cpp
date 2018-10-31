#include <iostream>
#include <vector>
#include <map>

using namespace std;

typedef map<char, int>::const_iterator MapIterator;

int main() {
    string input;
    map<char, int> counterMap;
    bool found = false;

    cout << "Please enter a Text:" << endl;

    while (!found) {
        getline(cin, input);
        if (cin.fail()) break;

        vector<char> charArray(input.c_str(), input.c_str() + input.size());

        for (char c : charArray) {
            if (c != '@') {
                if (counterMap.find(c) == counterMap.end()) { // not found
                    counterMap[c] = 1;
                } else {
                    counterMap[c]++;
                }
            } else {
                found = true;
                break;
            }
        }
    }
    for (MapIterator i = counterMap.begin(); i != counterMap.end(); i++) {
        cout << i->first << ": " << i->second << " times" << endl;
    }

    return 0;
}