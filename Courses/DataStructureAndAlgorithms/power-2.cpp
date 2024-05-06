/*
 * 
 */

#include <iostream>
#include <cmath>
using namespace std;

int GetLen(int num) {
    return log2(num) + 1;
}

void Convert(int num, int p) {
    if (p == 0) return;
    int digit = (num >> (p - 1)) & 1;
    if (!digit) {
        Convert(num, p - 1);
    } else {
        if (p != GetLen(num)) cout << '+';
        if (p == 1) cout << "2{0}";
        else if (p == 2) cout << "2";
        else {
            cout << "2{";
            Convert(p - 1, GetLen(p - 1));
            cout << "}";
        }
        Convert(num, p - 1);
    }
}

int main() {
    int num;
    cin >> num;
    Convert(num, GetLen(num));
    return 0;
}