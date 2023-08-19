#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestPalindrome(string s) {
        vector<int> hash(256, 0);
        int len = s.length();
        for (int i = 0; i < len; i++) {
            hash[s[i]]++;
        }
        int oddCount = 0;
        for (int i = 0; i < 256; i++) {
            if (hash[i] != 0 && hash[i] % 2 != 0) {
                oddCount++;
            }
        }
        if (oddCount) {
            return len - oddCount + 1;
        } else {
            return len - oddCount;
        }
    }
};

int main() {
    string s;
    cin >> s;
    cout << Solution().longestPalindrome(s) << endl;
    return 0;
}