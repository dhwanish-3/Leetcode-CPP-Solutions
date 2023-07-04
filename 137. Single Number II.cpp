#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int> mapping;
        for(int i=0;i<n;i++){
            mapping[nums[i]]++;
        }
        for(auto it: mapping){
            if(it.second==1) return it.first;
        }
        return -1;
    }
};

int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    cout<<Solution().singleNumber(v);
    return 0;
}