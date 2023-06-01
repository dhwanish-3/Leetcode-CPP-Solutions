#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        if(n==1 && grid[0][0]==0) return 1;
        if(grid[0][0]==1 || grid.back().back()==1) return -1;
        const vector<pair<int,int>> directions={{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};
        queue<pair<int,int>> q{{{0,0}}};
        vector<vector<bool>> visited(n,vector<bool>(n));
        visited[0][0]=true;
        int pathLength=0;
        while(!q.empty()){
            ++pathLength;
            int i,j,dx,dy;
            for(int size=q.size();size>0;--size){
                i=q.front().first; 
                j=q.front().second; 
                q.pop();
                for(auto d=directions.begin();d!=directions.end();++d){
                    auto& dir=*d;
                    dx=dir.first;
                    dy=dir.second;
                    int x=i+dx;
                    int y=i+dy;
                    if(x<0 || x==n || y<0 || y==n) continue;
                    if(grid[x][y]!=0 || visited[x][y]) continue;
                    if(x==n-1 && y==n-1) return pathLength+1;
                    q.emplace(x,y);
                    visited[x][y]=true;
                }
            }
        }
        return -1;
    }
};

int main(){
    int input;
    cin>>input;
    int n=input;
    vector<int> row;
    vector<vector<int>> binaryMatrix;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>input;
            row.push_back(input);
        }
        binaryMatrix.push_back(row);
    }
    cout<<Solution().shortestPathBinaryMatrix(binaryMatrix);
    return 0;
}