#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l=0,r=nums.size()-1;
        int mid=0;
        while(l<=r){
            mid=(l+r)/2;
            if(nums[mid]==target) return mid;
            else if(nums[mid]>target) r=mid-1;
            else l=mid+1;
        }
        return -1;
    }
};

int main(){
    int n,in,tar;
    vector<int> v;
    cin>>n;
    while(n--){
        cin>>in;
        v.push_back(in);
    }
    cin>>tar;
    cout<<Solution().search(v,tar);
    return 0;
}