#include <iostream>
#include <vector>
#include <regex>

using namespace std;

class Currency {
protected:
    string currency;
    int base;
public:
    explicit Currency(string currency) : currency(std::move(currency)) {
        this->base = 0;
    }

    Currency(string currency, int base) : currency(std::move(currency)), base(base) {}

    virtual ~Currency() = default;

    virtual void to_out() {
        cout << "Current currency: " << currency << endl;
    }
};

class Gulden : public Currency {
private:
    int value;
public:
    Gulden(int gold, int silver, int copper) : Currency("Gulden") {
        value = gold * 240 + silver * 4 + copper;
    }

    ~Gulden() = default;

    void convert_to_Thaler() {
        int gold = value / 240,
                silver = (value % 240) / 12,
                copper = (value % 240) % 12;
        cout << gold << " Taler, " << silver << " Silbergroschen, " << copper << " Pfennig" << endl;
    }

    void to_out() override {
        int gold = value / 240,
                silver = (value % 240) / 4,
                copper = (value % 240) % 4;
        cout << "Current currency: " << gold << " Gulden, " << silver << " Kreuzer, " << copper << " Pfennig" << endl;
    }
};

class Taler : public Currency {
private:
    int value;
public:
    Taler(int gold, int silver, int copper) : Currency("Taler") {
        value = gold * 240 + silver * 12 + copper;
    }

    ~Taler() = default;

    void convert_to_Gulden() {
        int gold = value / 240,
                silver = (value % 240) / 4,
                copper = (value % 240) % 4;
        cout << gold << " Gulden, " << silver << " Kreuzer, " << copper << " Pfennig" << endl;
    }

    void to_out() override {
        int gold = value / 240,
                silver = (value % 240) / 12,
                copper = (value % 240) % 12;
        cout << "Current currency: " << gold << " Taler, " << silver << " Silbergroschen, " << copper << " Pfennig" << endl;
    }

};

int main() {
    string buffer;
    Taler *taler = nullptr;
    Gulden *gulden = nullptr;

    cout << "Please enter currency values: ";
    cin >> buffer;

    try {
        int gold, silver, copper;
        regex regex_from_1(R"((\d+)t,(\d+)sgr,(\d+)pf)");
        regex regex_from_2(R"((\d+)fl,(\d+)x,(\d+)d)");
        smatch match;
        if (regex_search(buffer, match, regex_from_1) && match.size() > 1) {
            gold = stoi(match.str(1));
            silver = stoi(match.str(2));
            copper = stoi(match.str(3));
            taler = new Taler(gold, silver, copper);
            taler->to_out();
            cout << "In Gulden: ";
            taler->convert_to_Gulden();
        } else if (regex_search(buffer, match, regex_from_2) && match.size() > 1) {
            gold = stoi(match.str(1));
            silver = stoi(match.str(2));
            copper = stoi(match.str(3));
            gulden = new Gulden(gold, silver, copper);
            gulden->to_out();
            cout << "In Taler: ";
            gulden->convert_to_Thaler();
        } else {
            cout << "No match" << endl;
            cout << "Must be ...fl,...x,...d (Gulden) or ...t,...sgr,...pf (Taler)" << endl;
        }
    } catch (std::regex_error &e) {
        cout << "Syntax error in the regular expression" << endl;
    }

    return 0;
}