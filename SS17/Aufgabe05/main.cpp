#include <iostream>
#include <fstream>
#include <queue>

using namespace std;

string split_after_delimiter(string &str, char delimiter) {
    return str.substr(str.find(delimiter) + 1);
}

string split_before_delimiter(string &str, char delimiter) {
    return str.substr(0, str.find(delimiter));
}

struct CompareWeight {
    bool operator()(pair<int, string> pair1, pair<int, string> pair2) {
        return pair1.first < pair2.first;
    }
};

int main() {

    int weight;
    string line, head;
    typedef pair<int, string> lines;
    priority_queue<lines, vector<lines>, CompareWeight> sQueue;

    ifstream infile("data.txt");
    /**
     * read file line by line and push lines to queue
     * uses the weight to determine the order of elements in queue
     */
    while (getline(infile, line)) {
        weight = stoi(split_after_delimiter(line, '='));
        head = split_before_delimiter(line, '=');
        sQueue.push(make_pair(weight, head));
    }

    /**
     * Output text from first in queue, then pop it from heap
     */
    while (!sQueue.empty()) {
        cout << sQueue.top().second << endl;
        sQueue.pop();
    }

    return EXIT_SUCCESS;
}

