#include <bits/stdc++.h>
using namespace std;

class Solution{
    int m,n;
    const int mod=1e9+7;
    const vector<int> directions{0,1,0,-1,0};
    vector<vector<int>> dp;
    int dfs(const vector<vector<int>>& grid,int i,int j){
        if(dp[i][j]!=-1) return dp[i][j];
        dp[i][j]=1;
        for(int k=0;k<4;k++){
            const int x=i+directions[k];
            const int y=j+directions[k+1];
            if(x<0 || x==m || y<0 || y==n) continue;
            if(grid[x][y]<=grid[i][j]) continue;
            dp[i][j]+=dfs(grid,x,y);
            dp[i][j]%=mod;
        }
        return dp[i][j];
    }
public:
    int countPaths(vector<vector<int>>& grid) {
        m=grid.size();
        n=grid[0].size();
        int sol=0;
        dp.resize(m,vector<int>(n,-1));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                sol+=dfs(grid,i,j);
                sol%=mod;           
            }
        }
        return sol;
    }
};

int main(){
    int n,m,in;
    cin>>m>>n;
    vector<vector<int>> grid;
    for(int i=0;i<m;i++){
        vector<int> v;
        for(int j=0;j<n;i++){
            cin>>in;
            v.push_back(in);
        }
        grid.push_back(v);
    }
    
    return 0;
}