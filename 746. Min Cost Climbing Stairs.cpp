#include <bits/stdc++.h>
using namespace std;

//  1 D DP
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        int dp[n + 2];
        dp[n + 1] = 0;
        dp[n] = 0;
        for (int i = n - 1; i >= 0; i--) {
            dp[i] = cost[i] + min(dp[i + 1], dp[i + 2]);
        }
        return min(dp[0], dp[1]);
    }
};

// Space optimized
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        int one, two, three;
        three = 0;
        two = 0;
        for (int i = n - 1; i >= 0; i--) {
            one = cost[i] + min(two, three);
            three = two;
            two = one;
        }
        return min(one, three);
    }
};

int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    cout<<Solution().minCostClimbingStairs(v);
    return 0;
}