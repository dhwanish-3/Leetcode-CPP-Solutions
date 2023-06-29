#include <bits/stdc++.h>
using namespace std;

struct T{
    int i;
    int j;
    int keys;
    T(int i,int j,int keys): i(i), j(j), keys(keys) {}
};

class Solution {
    int getKeysCount(const vector<string>& grid){
        int count=0;
        for(int i=0;i<grid.size();i++){
            count+=count_if(grid[i].begin(),grid[i].end(),[](char c){ return 'a'<=c && c<= 'f';});
        }
        return count;
    }
    vector<int> getStart(const vector<string>& grid){
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]=='@') return {i,j};
            }
        }
        throw;
    }
public:
    int shortestPathAllKeys(vector<string>& grid) {
        int m=grid.size();
        int n=grid[0].length();
        int keysCount=getKeysCount(grid);
        int kKeys=(1<<keysCount)-1;
        const vector<int> dirs{0,1,0,-1,0};
        const vector<int> start=getStart(grid);
        int sol=0;
        queue<T> q{{{start[0],start[1],0}}};
        vector<vector<vector<bool>>> seen(m,vector<vector<bool>>(n,vector<bool>(kKeys)));
        seen[start[0]][start[1]][0]=true;
        while(!q.empty()){
            sol++;
            for(int s=q.size();s>0;s--){
                int i=q.front().i;
                int j=q.front().j;
                int keys=q.front().keys;
                q.pop();
                for(int k=0;k<4;k++){
                    int x=i+dirs[k];
                    int y=j+dirs[k+1];
                    if(x<0 || x==m || y<0 || y==n) continue;
                    char c=grid[x][y];
                    if(c=='#') continue;
                    int newKeys='a'<=c && c<='f'?keys|1<<c-'a':keys;
                    if(newKeys==kKeys) return sol;
                    if(seen[x][y][newKeys]) continue;
                    if('A'<=c && c<='F' && ((newKeys>>c-'A') & 1)==0) continue;
                    q.emplace(x,y,newKeys);
                    seen[x][y][newKeys]=true;
                }
            }
        }
        return -1;
    }
};

int main(){
    int n;
    cin>>n;
    vector<string> v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    cout<<Solution().shortestPathAllKeys(v);
    return 0;
}