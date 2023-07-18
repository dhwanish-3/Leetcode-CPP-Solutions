#include <bits/stdc++.h>
using namespace std;

class Solution {
    const vector<int> dirs = {0, 1, 0, -1, 0};
    void bfs(vector<vector<char>>& grid, int r, int c) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int, int>> q{{{r, c}}};
        grid[r][c] = '3';
        while (!q.empty()) {
            int i = q.front().first;
            int j = q.front().second;
            q.pop();
            for (int k=0 ; k<4 ; k++) {
                int x = i + dirs[k];
                int y = j + dirs[k+1];
                if (x<0 || x==m || y<0 || y==n) {
                    continue;
                }
                if (grid[x][y] != '1') {
                    continue;
                }
                q.emplace(x, y);
                grid[x][y] = '3';
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int sol = 0;
        for (int i=0; i<m ; i++) {
            for (int j=0 ; j<n ; j++) {
                if (grid[i][j] == '1') {
                    bfs(grid, i, j);
                    sol++;
                }
            }
        }
        return sol;
    }
};

int main(){
    int m,n;
    cin>>m>>n;
    vector<vector<char>> v(m, vector<char> (n));
    for (int i=0 ; i<m ; i++) {
        for (int j=0 ; j<n ; j++) {
            cin>>v[i][j];
        }
    }
    cout<<Solution().numIslands(v);
    return 0;
}