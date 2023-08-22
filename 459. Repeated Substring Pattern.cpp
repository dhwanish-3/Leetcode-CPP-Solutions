#include <bits/stdc++.h>
using namespace std;

// Approach 1: Brute Force
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int len = s.length();
        string sub;
        for (int i = 1; i <= len / 2; i++) {
            sub = s.substr(0, i);
            string check;
            if (len % i == 0) {
                while (check.length() <= len) {
                    if (s == check) {
                        return true;
                    }
                    check += sub;
                }
            }
        }
        return false;
    }
};

// Approach 2: Leetcode
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        string t = s + s;
        if (t.substr(1, t.length() - 2).find(s) != - 1) {
            return true;
        }
        return false;
    }
};

int main() {
    string s;
    cin >> s;
    cout << Solution().repeatedSubstringPattern(s) << endl;
    return 0;
}