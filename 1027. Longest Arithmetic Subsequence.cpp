#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int maxLength=0;
        vector<vector<int>> hash(nums.size(),vector<int>(1001));
        for(int i=0;i<nums.size();i++){
            for(int j=0;j<i;j++){
                int d=nums[i]-nums[j]+500;
                hash[i][d]=max(2,hash[j][d]+1);
                maxLength=max(maxLength,hash[i][d]);
            }
        }
        return maxLength;
    }
};

int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    cout<<Solution().longestArithSeqLength(v);
    
    return 0;
}