#include <bits/stdc++.h>
using namespace std;

class Solution {
    vector<int> dirs{0, 1, 0, -1, 0};
    bool dfs(vector<vector<char>>& board, string word, int i, int j, int k, vector<vector<bool>>& visited) {
        int m = board.size();
        int n = board[0].size();
        if (i < 0 || i >= m || j < 0 || j >= n) {
            return false;
        }
        if (board[i][j] != word[k]) {
            return false;
        }
        if (k == word.size() - 1) {
            return true;
        }
        visited[i][j] = true;
        for (int l = 0; l < 4; l++) {
            int x = i + dirs[l];
            int y = j + dirs[l + 1];
            if (x < 0 || x >= m || y < 0 || y >= n) {
                continue;
            }
            if (visited[x][y]) {
                continue;
            }
            if (dfs(board, word, x, y, k + 1, visited)) {
                return true;
            }
        }
        visited[i][j] = false;
        return false;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (dfs(board, word, i, j, 0, visited)) {
                    return true;
                }
            }
        }
        return false;
    }
};

int main(){
    int m, n;
    cin >> m >> n;
    vector<vector<char>> board(m, vector<char>(n));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n ; j++) {
            cin >> board[i][j];
        }
    }
    cout << Solution().exist(board, "ABCCED");
    return 0;
}