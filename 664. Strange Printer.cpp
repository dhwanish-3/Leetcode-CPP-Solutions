#include <bits/stdc++.h>
using namespace std;

class Solution {
    vector<vector<int>> dp;
    int strangePrinting(string& s, int i, int j) {
        if (i > j) {
            return 0;
        }
        if (dp[i][j] > 0) {
            return dp[i][j];
        }
        dp[i][j] = strangePrinting(s, i + 1, j) + 1;
        for (int k = i + 1; k <= j; k++) {
            if (s[k] == s[i]) {
                dp[i][j] = min(dp[i][j], strangePrinting(s, i, k - 1) + strangePrinting(s, k + 1, j));
            }
        }
        return dp[i][j];
    }
public:
    int strangePrinter(string s) {
        int n = s.length();
        dp.resize(n, vector<int>(n));
        return strangePrinting(s, 0, n - 1);
    }
};

int main(){
    string s;
    cin >> s;
    cout << Solution().strangePrinter(s) << endl;
    return 0;
}