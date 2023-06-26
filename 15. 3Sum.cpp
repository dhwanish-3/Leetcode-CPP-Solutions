#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> sol;
        sort(nums.begin(),nums.end());
        // for(int i=0;i<n;i++) cout<<nums[i]<<" ";
        cout<<endl;
        for(int i=0;i+2<n;i++){
            if(i>0 && nums[i]==nums[i-1]) continue;
            int l=i+1,r=n-1;
            while(l<r){
                if(nums[l]+nums[r]==(-nums[i])){
                    vector<int> v(3);
                    v[0]=nums[i];
                    v[1]=nums[l];
                    v[2]=nums[r];
                    sol.push_back(v);
                    l++;
                    r--;
                    while(l<r && nums[l]==nums[l-1]){
                        l++;
                    }
                    while(l<r && nums[r]==nums[r+1]){
                        r--;
                    }
                }else if(nums[l]+nums[r]>(-nums[i])){
                    r--;
                }else{
                    l++;
                }
            }
        }
        return sol;
    }
};

int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    vector<vector<int>> sol=Solution().threeSum(v);
    for(int i=0;i<sol.size();i++){
        for(int j=0;j<sol[i].size();j++){
            cout<<sol[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}