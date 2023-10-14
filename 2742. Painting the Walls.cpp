#include <bits/stdc++.h>
using namespace std;

class Solution {
    int memoization(vector<int>& cost, vector<int>& time, int i, int walls, vector<vector<int>>& dp) {
        if (walls <= 0) {
            return 0;
        }
        if (i < 0) {
            return 1e9;
        }
        if (dp[i][walls] != -1) {
            return dp[i][walls];
        }
        int take = cost[i] + memoization(cost, time, i - 1, walls - time[i] - 1, dp);
        int notTake = memoization(cost, time, i - 1, walls, dp);
        return dp[i][walls] = min(take, notTake);
    }
public:
    int paintWalls(vector<int>& cost, vector<int>& time) {
        int n = cost.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        return memoization(cost, time, n - 1, n, dp);
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> cost(n), time(n);
    for (int i = 0; i < n; i++) {
        cin >> cost[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> time[i];
    }
    cout << Solution().paintWalls(cost, time);
    return 0;
}