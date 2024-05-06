// Problem: 67 add bianry
// Date: 2024.04.16
// Author: Nulla

class Solution {
public:
    string addBinary(string a, string b) {
        int length_a = a.length();
        int length_b = b.length();

        while (length_a < length_b) {
            a = '0' + a;
            ++length_a;
        }
        while (length_b < length_a) {
            b = '0' + b;
            ++length_b;
        }

        for (int i = a.length() - 1; i > 0; --i) {
            a[i] = a[i] - '0' + b[i];
            if (a[i] >= '2') {
                a[i] = (a[i] - '0') % 2 + '0';
                a[i - 1] = a[i - 1] + 1;
            }
        }
        a[0] = a[0] - '0' + b[0];
        if (a[0] >= 2) {
            a[0] = (a[0] - '0') % 2 + '0';
            a = '1' + a;
        }
        return a;
    }
};