#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if(nums[0]>target) return 0;
        int n=nums.size();
        if(nums[n-1]<target) return n;
        int left=0;
        int right=n-1;
        int mid=0;
        while(left<right){
            mid=(left+right)/2;
            if(nums[mid]==target) return mid;
            else if(nums[mid]>target){
                right=mid;
            }
            else{
                left=mid+1;
            }
        }
        return left;
    }
};

int main(){
    int n,target;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    cin>>target;
    cout<<Solution().searchInsert(v,target);
    
    return 0;
}