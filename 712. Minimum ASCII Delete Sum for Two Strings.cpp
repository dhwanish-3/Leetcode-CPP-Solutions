#include <bits/stdc++.h>
using namespace std;

// Approach 1: DP - Memoization   --- Memory Limit Exceeded ---
class Solution {
    vector<int> s1Sum, s2Sum;
    int rec(string s1, string s2, int i, int j, vector<vector<int>>& dp) {
        if (i == 0 && j == 0) {
            return 0;
        } else if (i == 0) {
            return s2Sum[j - 1];
        } else if (j == 0) {
            return s1Sum[i - 1];
        } else {
            if (dp[i][j] != -1) {
                return dp[i][j];
            }
            if (s1[i - 1] == s2[j - 1]) {
                return dp[i][j] = rec(s1, s2, i - 1, j - 1, dp);
            } else {
                return dp[i][j] = min(s1[i - 1] + rec(s1, s2, i - 1, j, dp), s2[j - 1] + rec(s1, s2, i, j - 1, dp));
            }
        }
    }
public:
    int minimumDeleteSum(string s1, string s2) {
        int n1 = s1.length(), n2 = s2.length();
        vector<vector<int>> dp(n1, vector<int>(n2, -1));
        s1Sum.resize(n1);
        s2Sum.resize(n2);
        for (int k = 0; k < n1; k++) {
            if (k == 0) s1Sum[0] = s1[0];
            else s1Sum[k] = s1[k] + s1Sum[k - 1];
        }
        for (int k = 0; k < n2; k++) {
            if (k == 0) s2Sum[0] = s2[0];
            else s2Sum[k] = s2[k] + s2Sum[k - 1];
        }
        return rec(s1, s2, n1, n2, dp);
    }
};

// Approach 2: DP - Tabulation with space optimisation
class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
        if (n > m) {
            swap(s1, s2);
            swap(n, m);
        }
        vector<int> dp(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            dp[i] = dp[i - 1] + s1[i - 1];
        }
        for (int i = 0; i < m; i++) {
            vector<int> temp(n + 1, dp[0] + s2[i]);
            for (int j = 0; j < n; j++) {
                if (s2[i] == s1[j]) {
                    temp[j + 1] = dp[j];
                } else {
                    temp[j + 1] = min(dp[j] + s2[i] + s1[j], min(temp[j] + s1[j], dp[j + 1] + s2[i]));
                }
            }
            dp = temp;
        }
        return dp[n];
    }
};

int main(){
    string s1, s2;
    cin >> s1 >> s2;
    cout << Solution().minimumDeleteSum(s1, s2);
    return 0;
}