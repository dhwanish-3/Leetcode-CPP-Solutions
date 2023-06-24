#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int len=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=val){
                nums[len]=nums[i];
                len++;
            }
        }
        return len;
    }
};

int main(){
    int n,val;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    cin>>val;
    cout<<Solution().removeElement(v,val);
    return 0;
}