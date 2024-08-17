#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if (board.empty()) {
            return;
        }
        int m = board.size();
        int n = board[0].size();
        const vector<int> dirs = {0, 1, 0, -1, 0};
        queue<pair<int, int>> q;
        for (int i=0 ; i<m ; i++) {
            for (int j=0 ; j<n ; j++) {
                if (i==0 || i==m-1 || j==0 || j==n-1) {
                    if (board[i][j] == 'O') {
                        q.emplace(i, j);
                        board[i][j] = '*';
                    }
                }
            }
        }
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
                if (board[x][y] != 'O') {
                    continue;
                }
                q.emplace(x, y);
                board[x][y] = '*';
            }
        }
        for (int i=0; i<m ; i++) {
            for (int j=0 ; j<n ; j++) {
                if (board[i][j] == '*') {
                    board[i][j] = 'O';
                } else if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
            }
        }
    }
};