#include <bits/stdc++.h>
using namespace std;

class Solution {
    long long getCost(vector<int>& nums,vector<int>& cost,int target){
        long long res=0;
        for(int i=0;i<nums.size();i++){
            res+=abs(nums[i]-target)*static_cast<long long>(cost[i]);
        }
        return res;
    }
public:
    long long minCost(vector<int>& nums, vector<int>& cost) {
        long long sol=0;
        int n=nums.size();
        int mini=INT_MAX,maxi=INT_MIN;
        for(int i=0;i<n;i++){
            mini=min(mini,nums[i]);
            maxi=max(maxi,nums[i]);
        }
        while(mini<maxi){
            int mid=(mini+maxi)/2;
            long long first=getCost(nums,cost,mid);
            long long second=getCost(nums,cost,mid+1);
            sol=min(first,second);
            if(first<second) maxi=mid;
            else mini=mid+1;
        }
        return sol;
    }
};

int main(){
    int n;
    cin>>n;
    vector<int> nums(n),cost(n);
    for(int i=0;i<n;i++)
        cin>>nums[i];
    for(int i=0;i<n;i++)
        cin>>cost[i];
    cout<<Solution().minCost(nums,cost);
    return 0;
}