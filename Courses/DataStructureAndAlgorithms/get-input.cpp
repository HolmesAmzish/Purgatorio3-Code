// Program: get-input.cpp
// Date: 2024.04.15
// Author: Nulla
// Description: Get all the input of csoj.

#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<string> inputs;
    for (int i = 0; i < 64; i++) {
        string line;
        getline(cin, line);
        inputs.push_back(line);
    }
    for (string line : inputs) {
        cout << line << endl;
        if (line == "\n")
            break;
    }
    return 0;
}