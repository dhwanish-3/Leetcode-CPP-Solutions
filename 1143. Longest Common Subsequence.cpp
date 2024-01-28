#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n1 = text1.length(), n2 = text2.length();
        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));
        for (int i = 1; i <= n1; i++) {
            char c1 = text1[i - 1];
            for (int j = 1; j <= n2; j++) {
                char c2 = text2[j - 1];
                if (c1 == c2) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                }
                else {
                    dp[i][j] = max({dp[i - 1][j], dp[i][j - 1]});
                }
            }
        }
        return dp[n1][n2];
    }
};

int main() {
    string text1, text2;
    cin >> text1 >> text2;
    cout << Solution().longestCommonSubsequence(text1, text2) << endl;
    return 0;
}