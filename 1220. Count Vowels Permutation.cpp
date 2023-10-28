#include <bits/stdc++.h>
using namespace std;

// Approach 1 : DP - Recursion -> Memoization
class Solution {
    int mod = 1e9 + 7;
    vector<string> arr = {"ae", "eai", "iaeou", "oiu", "ua"};
    int index(char c) {
        switch(c) {
            case 'a': return 0;
            case 'e': return 1;
            case 'i': return 2;
            case 'o': return 3;
            case 'u': return 4;
            default: return 0;
        }
    }
    int recursion(int n, int i, vector<vector<int>>& dp) {
        if (n == 0) {
            return 1;
        }
        if (dp[n][i] != -1) {
            return dp[n][i];
        }
        int count = 0;
        for (int j = 1; j < arr[i].length(); j++) {
            count += (recursion(n - 1, index(arr[i][j]), dp) % mod);
        }
        return dp[n][i] = count;
    }
public:
    int countVowelPermutation(int n) {
        int count = 0;
        vector<vector<int>> dp(n, vector<int>(5, -1));
        for (int i = 0; i < 5; i++) {
            count += (recursion(n - 1, i, dp) % mod);
        }
        return count;
    }
};

// Approach 2 : DP - Iterative -> Tabulation
class Solution {
    int mod = 1e9 + 7;
    vector<string> arr = {"ae", "eai", "iaeou", "oiu", "ua"};
    int index(char c) {
        switch(c) {
            case 'a': return 0;
            case 'e': return 1;
            case 'i': return 2;
            case 'o': return 3;
            case 'u': return 4;
            default: return 0;
        }
    }
public:
    int countVowelPermutation(int n) {
        vector<vector<int>> dp(n, vector<int>(5, 0));
        for (int i = 0; i < 5; i++) {
            dp[0][i] = 1;
        }
        for (int i = 1; i < n; i++) {
            dp[i][0] = (dp[i - 1][1] + dp[i - 1][2] + dp[i - 1][4]) % mod;
            dp[i][1] = (dp[i - 1][0] + dp[i - 1][2]) % mod;
            dp[i][2] = (dp[i - 1][1] + dp[i - 1][3]) % mod;
            dp[i][3] = (dp[i - 1][2]) % mod;
            dp[i][4] = (dp[i - 1][2] + dp[i - 1][3]) % mod;
        }
        int count = 0;
        for (int i = 0; i < 5; i++) {
            count = (count + dp[n - 1][i]) % mod;
        }
        return count;
    }
};

int main() {
    int n;
    cin >> n;
    cout << Solution().countVowelPermutation(n) << endl;
    return 0;
}