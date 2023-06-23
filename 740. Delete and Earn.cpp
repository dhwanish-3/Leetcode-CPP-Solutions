#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        vector<int> bucket(10001,0);
        for(int i=0;i<nums.size();i++){
            bucket[nums[i]]+=nums[i];
        }
        int prev1=0;
        int prev2=0;
        for(int i=0;i<bucket.size();i++){
            int dp=max(prev1,prev2+bucket[i]);
            prev2=prev1;
            prev1=dp;
        }
        return prev1;
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