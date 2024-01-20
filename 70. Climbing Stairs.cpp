#include <bits/stdc++.h>
using namespace std;

// Dynamic Programming : Bottom Up (Tabulation)
class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n + 1, 0);
        if (n == 1 || n == 2) {
            return n;
        }
        dp[1] = 1;
        dp[2] = 2;
        for (int i = 3; i < n + 1; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
};

// Dynamic Programming : Top-Down (Memoization)
class Solution {
    vector<int> dp;
public:
    Solution () {
        dp.resize(46, -1);
    }
    int climbStairs(int n) {
        if (n == 2 || n == 1) {
            return n;
        } 
        if (dp[n] != -1) {
            return dp[n];
        }
        dp[n] = climbStairs(n - 1) + climbStairs(n - 2);
    }
};

int main(){
    int n;
    cin>>n;
    cout<<Solution().climbStairs(n);
    return 0;
}