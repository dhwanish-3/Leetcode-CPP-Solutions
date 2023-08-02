#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return true;
        int i=0;
        while(i<n-1){
            int start=i;
            int curJump=nums[i];
            int maxJump=INT_MIN;
            int nextIndex=i;
            int j=1;
            while(start+j<n && j<=curJump){
                if(start+j>=n-1) return true;
                if(maxJump<=start+j+nums[start+j]){
                    maxJump=start+j+nums[start+j];
                    nextIndex=start+j;
                }
                j++;
            }
            i=nextIndex;
            cout<<i<<endl;
            if(i>=n-1) return true;
            if(nextIndex-start==0) return false;
        }
        return false;
    }
};

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        for (int reach = 0; i < n && reach <= n; i++) {
            reach = max(reach, i + nums[i]);
        }
        return i == n;
    }
};

int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    cout<<Solution().canJump(v);
    return 0;
}