#include <iostream>
#include <regex>

using namespace std;

#include "CurrencyTable.cpp"

class Currency {
private:
    string label;
    // abstract hierarchy levels as label and conversion rate pairs
    typedef pair<string, int> labelRatesPair;
    labelRatesPair gold;
    labelRatesPair silver;
    labelRatesPair copper;
    int amount;
public:
    Currency() {
        label = "";
        amount = 0;
    }

    ~Currency() = default;

    void loadCurrency(const string &asText, CurrencyTable &table) {
        try {
            string gLabel, sLabel, cLabel;
            regex pattern(R"((\d+)([a-z]+),(\d+)([a-z]+),(\d+)([a-z]+))");
            smatch match;
            if (regex_search(asText, match, pattern) && match.size() > 1) {
                gLabel = match.str(2);
                sLabel = match.str(4);
                cLabel = match.str(6);
                label = table.getLabelByRatelabels(gLabel, sLabel, cLabel);
                gold = {gLabel, table.getRateLabelPairsByCurrency(label).at(0).first};
                silver = {sLabel, table.getRateLabelPairsByCurrency(label).at(1).first};
                copper = {cLabel, table.getRateLabelPairsByCurrency(label).at(2).first};
                amount = stoi(match.str(1)) * gold.second +
                         stoi(match.str(3)) * silver.second +
                         stoi(match.str(5)) * copper.second;
            } else {
                cout << "No match" << endl;
            }
        } catch (std::regex_error &regexError) {
            cout << "Syntax error in the regular expression" << endl;
        }
    }

    int getGold() const {
        return amount / gold.second;
    }

    int getSilver() const {
        return (amount % gold.second) / silver.second;
    }

    int getCopper() const {
        return ((amount % gold.second) % silver.second) / copper.second;
    }

    int getAmount() const {
        return amount;
    }

    string toString() {
        ostringstream buffer;
        label[0] = (char) toupper(label[0]);
        buffer << "Properly converted as " << label << ": "
               << getGold() << gold.first << ", "
               << getSilver() << silver.first << ", "
               << getCopper() << copper.first;
        return buffer.str();
    }

    string convert(const string &other, CurrencyTable &table) {
        if (table.isPresent(other)) {
            label = other;
            label[0] = (char) toupper(label[0]);
            gold = {table.getRateLabelPairsByCurrency(other).at(0).second,
                    table.getRateLabelPairsByCurrency(other).at(0).first};
            silver = {table.getRateLabelPairsByCurrency(other).at(1).second,
                      table.getRateLabelPairsByCurrency(other).at(1).first};
            copper = {table.getRateLabelPairsByCurrency(other).at(2).second,
                      table.getRateLabelPairsByCurrency(other).at(2).first};
            ostringstream buffer;
            buffer << "Properly converted as " << label << ": "
                   << getGold() << gold.first << ", "
                   << getSilver() << silver.first << ", "
                   << getCopper() << copper.first;
            return buffer.str();
        } else return "Error: Unkown Currency";

    }

};
