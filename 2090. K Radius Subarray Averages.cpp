#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        vector<int> avg(nums.size(),-1);
        if((2*k+1)>nums.size()) return avg;
        vector<int64_t> prefixSum(nums.size());
        for(int i=0;i<nums.size();i++){
            if(i==0) prefixSum[i]=nums[i];
            else prefixSum[i]=nums[i]+prefixSum[i-1];
        }
        for(int i=k;i+k<nums.size();i++){
            avg[i]=(prefixSum[i+k]-(i-k-1<0?0:prefixSum[i-k-1]))/(2*k+1);
        }
        return avg;
    }
};

int main(){
    int n,k;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    cin>>k;
    vector<int> avg=Solution().getAverages(v,k);
    for(int i=0;i<avg.size();i++){
        cout<<avg[i]<<" ";
    }
    return 0;
}