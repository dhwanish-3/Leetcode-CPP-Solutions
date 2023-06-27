#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int minLength=INT_MAX;
        int n=nums.size();
        int curSum=0;
        int start=0;
        for(int i=0;i<n;i++){
            curSum+=nums[i];
            while(curSum>=target){
                minLength=min(minLength,i-start+1);
                curSum-=nums[start];
                start++;
            }
        }
        return minLength==INT_MAX?0:minLength;
    }
};

int main(){
    int n,tar;
    cin>>tar>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    cout<<Solution().minSubArrayLen(tar,v);
    
    return 0;
}