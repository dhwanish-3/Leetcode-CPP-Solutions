#include <bits/stdc++.h>
using namespace std;

class Solution {
    void dfs(vector<int>& cookies,int s,int k,vector<int>&& children,int& sol){
        if(s==cookies.size()){
            sol=min(sol,*max_element(children.begin(),children.end()));
            return;
        }
        for(int i=0;i<k;i++){
            children[i]+=cookies[s];
            dfs(cookies,s+1,k,move(children),sol);
            children[i]-=cookies[s];
        }
    }
public:
    int distributeCookies(vector<int>& cookies, int k) {
        int sol=INT_MAX;
        dfs(cookies,0,k,vector<int>(k),sol);
        return sol;
    }
};

int main(){
    int n,k;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    cin>>k;
    cout<<Solution().distributeCookies(v,k);
    return 0;
}