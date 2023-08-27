#include <bits/stdc++.h>
using namespace std;

// Approach 1: Recursion - TLE
class Solution {
    bool dfs(vector<int>& stones, int i, int jump) {
        if (i == stones.size() - 1) {
            return true;
        }
        for (int j = i + 1; j < stones.size(); j++) {
            if (stones[j] - stones[i] > jump + 1) {
                return false;
            }
            if (stones[j] - stones[i] < jump - 1) {
                continue;
            }
            if (dfs(stones, j, stones[j] - stones[i])) {
                return true;
            }
        }
        return false;
    }
public:
    bool canCross(vector<int>& stones) {
        return dfs(stones, 0, 0);
    }
};

// Approach 2: Recursion with Memoization
class Solution {
    bool dfs(vector<int>& stones, int i, int jump, vector<vector<int>>& dp) {
        if (i == stones.size() - 1) {
            return true;
        }
        if (dp[i][jump] != -1) {
            return dp[i][jump];
        }
        for (int j = i + 1; j < stones.size(); j++) {
            if (stones[j] - stones[i] > jump + 1) {
                dp[i][jump] = false;
                return false;
            }
            if (stones[j] - stones[i] < jump - 1) {
                continue;
            }
            if (dfs(stones, j, stones[j] - stones[i], dp)) {
                dp[i][jump] = true;
                return true;
            }
        }
        dp[i][jump] = false;
        return false;
    }
public:
    bool canCross(vector<int>& stones) {
        int n = stones.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return dfs(stones, 0, 0, dp);
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> stones(n);
    for (int i = 0; i < n; i++) {
        cin >> stones[i];
    }
    cout << Solution().canCross(stones) << endl;
    return 0;
}