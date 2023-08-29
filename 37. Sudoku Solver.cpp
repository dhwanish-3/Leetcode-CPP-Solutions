#include <bits/stdc++.h>
using namespace std;

class Solution {
    bool isSafe(vector<vector<char>> board, int r, int c, char val) {
        for (int row = 0; row < 9; row++) {
            if (board[row][c] == val) {
                return false;
            }
        }
        for (int col = 0; col < 9; col++) {
            if (board[r][col] == val) {
                return false;
            }
        }
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[i + r - r % 3][j + c - c % 3] == val) {
                    return false;
                }
            }
        }
        return true;
    }
    bool solve(vector<vector<char>>& board, int r, int c) {
        if (r == 9) {
            return true;
        }
        if (c == 9) {
            return solve(board, r + 1, 0);
        }
        if (board[r][c] != '.') {
            return solve(board, r, c + 1);
        }
        for (char ch = '1'; ch <= '9'; ch++) {
            if (isSafe(board, r, c, ch)) {
                board[r][c] = ch;
                if (solve(board, r, c + 1)) {
                    return true;
                }
                board[r][c] = '.';
            }
        }
        return false;
    }
public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board, 0, 0);
    }
};

int main() {
    vector<vector<char>> board(9, vector<char>(9,'.'));
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cin >> board[i][j];
        }
    }
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}