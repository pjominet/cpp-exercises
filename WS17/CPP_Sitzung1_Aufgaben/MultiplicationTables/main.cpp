#include <iostream>

using namespace std;

int main() {
    int result = 0;
    bool run = true;
    char answer = 'n';

    while (run) {
        for (int i = 0; i <= 10; i++) {
            for (int j = 0; j <= 10; j++) {
                result = i * j;
                cout << i << " * " << j << " = " << result << endl;
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