#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int maxLen=0;
        int curLen=0;
        unordered_set<int> hash{nums.begin(),nums.end()};
        for(int i=0;i<nums.size();i++){
            if(hash.count(nums[i]-1)) continue;
            curLen=1;
            int num=nums[i]+1;
            while(hash.count(num)){
                curLen++;
                num++;
            }
            maxLen=max(maxLen,curLen);
        }
        return maxLen;
    }
};

int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    cout<<Solution().longestConsecutive(v);
    return 0;
}