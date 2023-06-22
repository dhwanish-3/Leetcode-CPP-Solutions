#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int odd=0,even=0;
        for(int i=0;i<nums.size();i++){
            if(i%2==0) even+=nums[i];
            else odd+=nums[i];
        }
        cout<<odd<<" "<<even<<endl;
        return max(odd,even);
    }
};

int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    cout<<Solution().rob(v);
    
    return 0;
}