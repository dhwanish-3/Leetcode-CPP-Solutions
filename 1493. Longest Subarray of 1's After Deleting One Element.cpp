#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int longestSubarray(vector<int>& nums) {
        int n=nums.size();
        vector<int> zeroes;
        zeroes.push_back(-1);
        for(int i=0;i<n;i++){
            if(nums[i]==0) zeroes.push_back(i);
        }
        zeroes.push_back(n);
        int size=zeroes.size();
        if(size==2 || size==3) return n-1;
        int len=0;
        for(int i=1;i<size-1;i++){
            len=max(len,zeroes[i+1]-zeroes[i-1]);
        }
        return len-2;
    }
};

int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    cout<<Solution().longestSubarray(v);
    return 0;
}