#include <bits/stdc++.h>
using namespace std;

class Solution {
    static const int N = 127;
    int dp[N][N];
    string str;
    int n;
    int numDigits(int x) {
        return x == 1 ? 0 : x < 10 ? 1 : x < 100 ? 2 : 3;
    }
    int solve(int left, int k) {
        if (k < 0) {
            return N;
        }
        if (left >= n || n - left <= k) {
            return 0;
        }
        if (dp[left][k] != -1) {
            return dp[left][k];
        }
        int sol = n;
        int cnt[26] = {0};
        for (int j = left, most = 0; j < n; j++) {
            most = max(most, ++cnt[str[j] - 'a']);
            sol = min(sol, 1 + numDigits(most) + solve(j + 1, k - (j - left + 1 - most)));
        }
        return dp[left][k] = sol;
    }
public:
    int getLengthOfOptimalCompression(string s, int k) {
        str = s;
        n = s.size();
        memset(dp, -1, sizeof(dp));
        return solve(0, k);
    }
};

int main() {
    string s;
    int k;
    cin >> s;
    cin >> k;
    cout << Solution().getLengthOfOptimalCompression(s, k);
    return 0;
}