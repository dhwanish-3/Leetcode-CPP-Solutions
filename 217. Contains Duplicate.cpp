#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        map<int,int> mapp;
        for(int i=0;i<nums.size();i++){
            if(mapp.find(nums[i])==mapp.end()){
                mapp[nums[i]]=i;
            }else return true;
        }
        return false;
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
    cout<<Solution().containsDuplicate(v);
    return 0;
}