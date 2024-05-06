// Problem: 3110
// Date: 2024.04.16
// Author: Nulla

class Solution {
    public:
    int scoreOfString(string s) {
        int score = 0;
        for (int i = 1; i < s.length(); i++) {
            score += abs(s[i] - s[i - 1]);
        }
        return score;
    }
};