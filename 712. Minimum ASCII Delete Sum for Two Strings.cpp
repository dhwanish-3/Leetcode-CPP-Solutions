#include <bits/stdc++.h>
using namespace std;

class Solution {
    int getSum(string s, int n) {
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += s[i];
        }
        return sum;
    }
    int recursion(string s1, string s2, int n, int m,vector<vector<int>>& dp) {
        if (m == 0) {
            return dp[n][m] = getSum(s1, n);
        }
        if (n == 0) {
            return dp[n][m] = getSum(s2, m);
        }
        if (dp[n][m] != -1) {
            return dp[n][m];
        }
        if (s1[n - 1] == s2[m - 1]) {
            return dp[n][m] = recursion(s1, s2, n - 1, m - 1, dp);
        } else {
            int one = s1[n - 1] + recursion(s1, s2, n - 1, m, dp);
            int two = s2[m - 1] + recursion(s1, s2, n, m - 1, dp);
            return dp[n][m] = min(one, two);
        }
    }
public:
    int minimumDeleteSum(string s1, string s2) {
        int n = s1.length();
        int m = s2.length();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        return recursion(s1, s2, n, m, dp);
    }
};

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
                } else{
                    temp[j + 1] = min(dp[j] + s2[i] + s1[j], min(temp[j] + s1[j], dp[j + 1] + s2[i]));
                }
            }
            dp = temp;
        }
        return dp[n];
    }
};

int main(){
    string s1,s2;
    cin >> s1 >> s2;
    cout << Solution().minimumDeleteSum(s1,s2);
    return 0;
}