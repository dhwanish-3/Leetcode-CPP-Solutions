#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumLength(string s) {
        int n = s.length();
        if (n == 1) {
            return n;
        }
        int l = 0, r = n - 1;
        while (l < r && s[l] == s[r]) {
            char ch = s[l];
            while (l <= r && s[l] == ch) {
                l++;
            }
            while (r >= l && s[r] == ch) {
                r--;
            }
        }
        return r - l + 1;
    }
};

int main() {
    string s;
    cin >> s;
    cout << Solution().minimumLength(s);
    return 0;
}