#include <bits/stdc++.h>
using namespace std;

class Solution{
    void dfs(vector<vector<int>>& grid, int i, int j, int i0, int j0, vector<vector<bool>>& visited, vector<pair<int,int>>& island){
        if (i<0 || i==grid.size() || j<0 || j==grid[0].size()) {
            return;
        }
        if (grid[i][j] == 0 || visited[i][j]) {
            return;
        }
        visited[i][j] = true;
        island.emplace_back(i - i0, j - j0);
        dfs(grid, i+1, j, i0, j0, visited, island);
        dfs(grid, i-1, j, i0, j0, visited, island);
        dfs(grid, i, j+1, i0, j0, visited, island);
        dfs(grid, i, j-1, i0, j0, visited, island);
    }
public:
    int numDistinctIslands(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        set<vector<pair<int,int>>> islands;
        vector<vector<bool>> visited(m, vector<bool>(n));
        for (int i=0 ; i<m ; i++) {
            for (int j=0 ; j<n ; j++) {
                vector<pair<int,int>> island;
                dfs(grid, i, j, i, j, visited, island);
                if (!island.empty()) {
                    islands.insert(island);
                }
            }
        }
        return islands.size();
    }
};

int main(){
    
    
    return 0;
}