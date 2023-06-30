#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        map<int,int> hash;
        for(int i=0;i<nums.size();i++){
            auto f=hash.find(nums[i]);
            if(f!=hash.end() && abs(f->second-i)<=k) return true;
            hash[nums[i]]=i;
        }
        return false;
    }
};

int main(){
    int n,k;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    cin>>k;
    cout<<Solution().containsNearbyDuplicate(v,k);
    return 0;
}