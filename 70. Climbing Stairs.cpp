#include <bits/stdc++.h>
using namespace std;

Dynamic Programming : Bottom Up (Tabulation)
class Solution {
public:
    int climbStairs(int n) {
        if(n<=3) return n;
        vector<int> steps(n);
        steps[0]=1;
        steps[1]=2;
        for(int i=2;i<n;i++){
            steps[i]=steps[i-1]+steps[i-2];
        }
        return steps[n-1];
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