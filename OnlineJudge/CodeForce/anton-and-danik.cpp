// Problem: 734 A Anton and Danik
// Date: 2024.04.16
// Author: Nulla

#include <iostream>
using namespace std;

int main() {
    int rounds;
    string wins;
    cin >> rounds >> wins;

    int anton = 0, danik = 0;
    for (int i = 0; i < rounds; ++i) {
        if (wins[i] == 'A')
            anton++;
        else if (wins[i] == 'D')
            danik++;
    }

    if (anton < danik)
        cout << "Danik" << endl;
    else if (danik < anton)
        cout << "Anton" << endl;
    else cout << "Friendship" << endl;

    return 0;
}