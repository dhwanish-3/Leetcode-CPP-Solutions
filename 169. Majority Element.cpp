#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count=0;
        int sol=0;
        for(int i=0;i<nums.size();i++){
            if(count==0) sol=nums[i];
            count+=(nums[i]==sol?1:-1);
        }
        return sol;
    }
};

int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin>>v[i];

    cout<<Solution().majorityElement(v);
    return 0;
}