#include <iostream>
#include <map>
#include <vector>
#include <regex>

using namespace std;

#ifndef CURRENCYTABLE_CPP
#define CURRENCYTABLE_CPP

class CurrencyTable {
private:
    typedef pair<int, string> rateLabelPair;
    map<string, vector<rateLabelPair>> currencies;
public:
    CurrencyTable() = default;

    ~CurrencyTable() = default;

    void loadCurrencies(string &data) {
        try {
            string label, gLabel, sLabel, cLabel;
            int gRate, sRate, cRate;
            regex pattern(R"(([a-z]+):([a-z]+=\d+),([a-z]+=\d+),([a-z]+=\d+))");
            smatch match;
            if (regex_search(data, match, pattern) && match.size() > 1) {
                label = match.str(1);
                // gold
                gRate = stoi(split_after_delimiter(match.str(2), '='));
                gLabel = split_before_delimiter(match.str(2), '=');
                rateLabelPair gold(gRate, gLabel);
                // silver
                sRate = stoi(split_after_delimiter(match.str(3), '='));
                sLabel = split_before_delimiter(match.str(3), '=');
                rateLabelPair silver(sRate, sLabel);
                // copper
                cRate = stoi(split_after_delimiter(match.str(4), '='));
                cLabel = split_before_delimiter(match.str(4), '=');
                rateLabelPair copper(cRate, cLabel);
                // add to list
                vector<rateLabelPair> rlp;
                rlp.push_back(gold);
                rlp.push_back(silver);
                rlp.push_back(copper);
                // add to map
                currencies.insert(make_pair(label, rlp));
            } else {
                cout << "No match" << endl;
            }
        } catch (std::regex_error &regexError) {
            cout << "Syntax error in the regular expression" << endl;
        }
    }

    string split_after_delimiter(const string &str, char delimiter) {
        return str.substr(str.find(delimiter) + 1);
    }

    string split_before_delimiter(const std::string &str, char delimiter) {
        return str.substr(0, str.find(delimiter));
    }

    vector<rateLabelPair> getRateLabelPairsByCurrency(const string &currency) {
        return currencies.find(currency)->second;
    }

    string getLabelByRatelabels(const string &gLabel, const string &sLabel, const string &cLabel) {
        for (auto &currency : currencies) {
            if (currency.second.at(0).second == gLabel &&
                currency.second.at(1).second == sLabel &&
                currency.second.at(2).second == cLabel)
                return currency.first;
        }
    }

    bool isPresent(const string &label) {
        bool test = false;
        for (auto &currency : currencies) {
            if(currency.first == label)
                test = true;
        }
        return test;
    }

    string toString() {
        ostringstream buffer;
        buffer << size() << " known Currencies: " << endl;
        for (auto &currency : currencies) {
            buffer << currency.first << endl;
        }
        return buffer.str();
    }

    int size() {
        int counter = 0;
        for (auto &currency : currencies) {
            counter++;
        }
        return counter;
    }
};

#endif
