#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int sum[10001] = {0};
        for (int i = 0; i < nums.size(); i++) {
            sum[nums[i]] += nums[i];
        }
        int dp[10001] = {0};
        dp[1] = sum[1];
        for (int i = 2; i < 10001; i++) {
            dp[i] = max(dp[i - 1], sum[i] + dp[i - 2]);
        }
        return dp[10000];
    }
};

int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    cout<<Solution().deleteAndEarn(v);    
    return 0;
}