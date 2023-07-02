#include <bits/stdc++.h>
using namespace std;

class Solution {
    void backtrack(vector<vector<int>>& requests,int start,vector<int>& in,vector<int>& out,int& ans){
        if(start==requests.size()){
            if(in==out){
                ans=max(ans,accumulate(in.begin(),in.end(),0));
            }
        }else{
            backtrack(requests,start+1,in,out,ans);
            ++out[requests[start][0]];
            ++in[requests[start][1]];
            backtrack(requests,start+1,in,out,ans);
            --out[requests[start][0]];
            --in[requests[start][1]];
        }
    }
public:
    int maximumRequests(int n, vector<vector<int>>& requests) {
        int sol=0;
        vector<int> in(n),out(n);
        backtrack(requests,0,in,out,sol);
        return sol;
    }
};

int main(){
    int n;
    cin>>n;
    vector<vector<int>> v(n,vector<int>(2));
    for(int i=9;i<n;i++){
        cin>>v[i][0]>>v[i][1];
    }
    cout<<Solution().maximumRequests(n,v);
    return 0;
}