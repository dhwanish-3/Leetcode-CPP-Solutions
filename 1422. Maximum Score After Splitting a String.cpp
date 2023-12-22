#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxScore(string s) {
        int n = s.length();
        if (n == 2) {
            if (s == "00" || s == "11") {
                return 1;
            } else if (s == "01") {
                return 2;
            } else if (s == "10") {
                return 0;
            }
        }
        vector<int> ones(n, 0);
        vector<int> zeroes(n, 0);
        if (s[0] == '0') {
            zeroes[0] = 1;
        }
        for (int i = 1; i < n; i++) {
            if (s[i] == '0') {
                zeroes[i] = zeroes[i - 1] + 1;
            } else {
                zeroes[i] = zeroes[i - 1];
            }
        }
        if (s[n - 1] == '1') {
            ones[n - 1] = 1;
        }
        for (int i = n - 2; i >= 0; i--) {
            if (s[i] == '1') {
                ones[i] = ones[i + 1] + 1;
            } else {
                ones[i] = ones[i + 1];
            }
        }
        int sol = 0;
        for (int i = 1; i < n - 1; i++) {
            sol = max(sol, zeroes[i] + ones[i]);
        }
        return sol;
    }
};

int main() {
    string s;
    cin >> s;
    cout << Solution().maxScore(s);
    return 0;
}