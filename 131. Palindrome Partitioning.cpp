#include <bits/stdc++.h>
using namespace std;

class Solution {
    bool palindrome(string s) {
        int l = 0, r = s.length() - 1;
        while (l < r && s[l] == s[r]) {
            l++;
            r--;
        }
        return l >= r;
    }
    void backtrack(string s, int i,string curStr, vector<string>& cur, vector<vector<string>>& sol) {
        if (i == s.length()) {
            if (curStr == "")
                sol.push_back(cur);
            return;
        }
        curStr += s[i];
        if (palindrome(curStr)) {
            cur.push_back(curStr);
            backtrack(s, i + 1, "", cur, sol);
            cur.pop_back();
        }
        backtrack(s, i + 1, curStr, cur, sol);
    }
public:
    vector<vector<string>> partition(string s) {
        vector<string> cur;
        vector<vector<string>> sol;
        backtrack(s, 0, "", cur, sol);
        return sol;
    }
};

int main() {
    string s;
    cin >> s;
    vector<vector<string>> sol = Solution().partition(s);
    for (vector<string> v : sol) {
        for (string s : v) {
            cout << s << " ";
        }
        cout << endl;
    }
    return 0;
}