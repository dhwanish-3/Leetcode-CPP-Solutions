#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        int prod=1;
        vector<int> zeroes;
        for(int i=0;i<n;i++){
            if(nums[i]!=0) prod*=nums[i];
            else zeroes.push_back(i);
        }
        vector<int> sol(n,0);
        int size=zeroes.size();
        if(size>1) return sol;
        for(int i=0;i<n;i++){
            if(!zeroes.empty() && zeroes[0]!=i){
                sol[i]=prod;
            }else{
                sol[i]=prod/nums[i];
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
    vector<int> sol=Solution().productExceptSelf(v);
    for(int i=0;i<sol.size();i++) cout<<sol[i]<<" ";
    return 0;
}