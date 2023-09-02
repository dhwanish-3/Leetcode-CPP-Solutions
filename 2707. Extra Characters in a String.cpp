#include <bits/stdc++.h>
using namespace std;

// Approach 1: Recursion - TLE
// Time complexity: O(2^n)
// Space complexity: O(n)
class Solution {
    int recursion(string s, unordered_map<string, int> hash, int i) {
        if (i >= s.length()) {
            return 0;
        }
        string curString = "";
        int minExtra = s.length();
        int curExtra = 0;
        int nextExtra = 0;
        for (int j = i; j < s.length(); j++) {
            curString += s[j];
            curExtra = hash.count(curString) ? 0 : curString.length();
            nextExtra = recursion(s, hash, j + 1);
            minExtra = min(minExtra, curExtra + nextExtra);
        }
        return minExtra;
    }
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        unordered_map<string, int> hash;
        for (int i = 0; i < dictionary.size(); i++) {
            hash[dictionary[i]]++;
        }
        return recursion(s, hash, 0);
    }
};

// Approach 2: DP - Memoization - TLE
class Solution {
    int recursion(string s, unordered_map<string, int> hash, vector<int>& dp, int i) {
        if (i >= s.length()) {
            return 0;
        }
        if (dp[i] != -1) {
            return dp[i];
        }
        string curString = "";
        int minExtra = s.length();
        int curExtra = 0;
        int nextExtra = 0;
        for (int j = i; j < s.length(); j++) {
            curString += s[j];
            curExtra = hash.count(curString) ? 0 : curString.length();
            nextExtra = recursion(s, hash, dp, j + 1);
            minExtra = min(minExtra, curExtra + nextExtra);
        }
        return dp[i] = minExtra;
    }
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        unordered_map<string, int> hash;
        vector<int> dp(s.length(), -1);
        for (int i = 0; i < dictionary.size(); i++) {
            hash[dictionary[i]]++;
        }
        return recursion(s, hash, dp, 0);
    }
};

// Approach 3: DP - Tabulation
class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        unordered_map<string, int> hash;
        vector<int> dp(s.length() + 1, 0);
        for (int i = 0; i < dictionary.size(); i++) {
            hash[dictionary[i]]++;
        }
        int minExtra = s.length();
        int curExtra = 0;
        int nextExtra = 0;
        for (int i = s.length() - 1; i >= 0; i--) {
            string curStr = "";
            minExtra = s.length();
            for (int j = i; j < s.length(); j++) {
                curStr += s[j];
                curExtra = hash.count(curStr) ? 0 : curStr.length();
                nextExtra = dp[j + 1];
                minExtra = min(minExtra, curExtra + nextExtra);
            }
            dp[i] = minExtra;
        }
        return dp[0];
    }
};

int main() {
    string s;
    int n;
    cin >> s >> n;
    vector<string> dictionary(n);
    for (int i = 0; i < n; i++) {
        cin >> dictionary[i];
    }
    cout << Solution().minExtraChar(s, dictionary) << endl;
    return 0;
}