#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        if(n==1 && grid[0][0]==0) return 1;
        if(grid[n-1][n-1] || grid[0][0]==1) return -1;
        const vector<pair<int,int>> directions={{-1,-1},{-1,0},{-1,1},{0,-1},{0,0},{0,1},{1,-1},{1,0},{1,1}};
        queue<pair<int,int>> q{{{0,0}}};
        vector<vector<bool>> visited(n,vector<bool>(n));
        visited[0][0]=true;
        int pathLength=0;
        while(!q.empty()){
            ++pathLength;
            int i,j,dx,dy;
            for(int x=q.size();x>0;x--){
                i=q.front().first; 
                j=q.front().second; 
                q.pop();
                for(int d=0;d<9;d++){
                    dx=directions[d].first;
                    dy=directions[d].second;
                }
            }
        }
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
    
    return 0;
}