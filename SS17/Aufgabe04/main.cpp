#include <iostream>
#include <fstream>

using namespace std;

#include "CurrencyTable.cpp"
#include "Currency.cpp"

int main() {
    bool run = true;
    char answer = 'n';
    string buffer, line;
    CurrencyTable table;
    Currency currency;

    ifstream data;
    data.open("currencies.txt");
    if (!data) {
        cout << "currencies.txt not found!" << endl;
    } else {
        while(!data.eof()) {
            getline(data, line);
            table.loadCurrencies(line);
        }
        cout << table.toString() << endl;
    }
    data.close();

    while(run) {
        cout << "Please enter currency values: ";
        cin >> buffer;
        cout << "Input as: " << buffer << endl;

        currency.loadCurrency(buffer, table);
        cout << "Base amount: " << currency.getAmount() << endl;
        cout << currency.toString() << endl;

        cout << "Convert to other currency: ";
        cin >> buffer;
        cout << currency.convert(buffer, table) << endl;

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