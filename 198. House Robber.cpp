#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        int dp[n + 2];
        memset(dp, 0, sizeof(dp));
        for (int i = n - 1; i >= 0; i--) {
            dp[i] = max(dp[i + 1], nums[i] + dp[i + 2]);
        }
        return dp[0];
    }
};

int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    cout<<Solution().rob(v);
    
    return 0;
}