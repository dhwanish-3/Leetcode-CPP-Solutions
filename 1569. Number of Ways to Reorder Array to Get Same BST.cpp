#include <bits/stdc++.h>
using namespace std;

class Solution {
    static const int mod=1e9+7;
    vector<vector<int>> v;
    void generate(int numRows) {
        for(int i=0;i<numRows;i++){
            v.push_back(vector<int>(i+1,1));
        }
        for(int i=2;i<numRows;i++){
            for(int j=1;j<v[i].size()-1;j++){
                v[i][j]=(v[i-1][j]+v[i-1][j-1])%mod;
            }
        }
    }
    int ways(vector<int>& nums){
        if(nums.size()<=2) return 1;
        vector<int> leftTree;
        vector<int> rightTree;
        for(int i=1;i<nums.size();i++){
            if(nums[i]<nums[0]) leftTree.push_back(nums[i]);
            else rightTree.push_back(nums[i]);
        }
        long sol=v[nums.size()-1][leftTree.size()];
        sol=(sol*ways(leftTree))%mod;
        sol=(sol*ways(rightTree))%mod;
        return sol;
    }
public:
    int numOfWays(vector<int>& nums){
        generate(nums.size()+1);
        return ways(nums)-1;
    }
};

int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    cout<<Solution().numOfWays(v);
    return 0;
}