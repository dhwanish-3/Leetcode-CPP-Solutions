#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int n = s.length();
        int count = 0;
        for (int i = 0; i < n - 1; i++) {
            count += s[i] == '1' ? 1 : 0;
        }
        if (s[n - 1] == '1') {
            for (int i = 0; i < n - 1; i++) {
                s[i] = i < count ? '1' : '0';
            }
        } else {
            s[n - 1] = '1';
            for (int i = 0; i < n - 1; i++) {
                s[i] = i < count - 1 ? '1' : '0';
            }
        }
        return s;
    }
};

int main() {
    string s;
    cin >> s;
    cout << Solution().maximumOddBinaryNumber(s);
    return 0;
}