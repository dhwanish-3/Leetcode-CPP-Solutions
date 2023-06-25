#include <bits/stdc++.h>
using namespace std;

class Solution {
    int mod=1e9+7;
    vector<vector<int>> dp;
    int count(vector<int>& locations, int start, int finish, int fuel) {
        if(fuel<0) return 0;
        if(dp[start][fuel]!=-1) return dp[start][fuel];
        int sol=start==finish?1:0;
        for(int j=0;j<locations.size();j++){
            if(j==start) continue;
            sol+=count(locations,j,finish,fuel-abs(locations[start]-locations[j]));
            sol%=mod;
        }
        dp[start][fuel]=sol;
        return sol;
    }
public:
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        dp.resize(locations.size(),vector<int>(fuel+1,-1));
        return count(locations,start,finish,fuel);
    }
};

int main(){
    int n,start,end,fuel;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    cin>>start>>end>>fuel;
    cout<<Solution().countRoutes(v,start,end,fuel);    
    return 0;
}