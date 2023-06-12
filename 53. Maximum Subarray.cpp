#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum=INT_MIN,currSum=0;
        for(int i=0;i<nums.size();i++){
            currSum+=nums[i];
            maxSum=max(maxSum,currSum);
            if(currSum<0) currSum=0;
        }
        return maxSum;
    }
};

int main(){
    int n,in;
    cin>>n;
    vector<int> v;
    for(int i=0;i<n;i++){
        cin>>in;
        v.push_back(in);
    }
    cout<<Solution().maxSubArray(v);
    return 0;
}