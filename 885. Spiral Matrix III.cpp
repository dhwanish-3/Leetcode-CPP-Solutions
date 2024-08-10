#include <bits/stdc++.h>
using namespace std;

class Solution {
    vector<vector<int>> sol;
    bool safe(int rows, int cols, int i, int j) {
        if (i < rows && i >= 0 && j < cols && j >= 0) {
            return true;
        }
        return false;
    }
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int r, int c) {
        int dir = 1;
        sol.push_back({r, c});
        while (sol.size() < rows * cols) {
            for (int i = c + 1; i <= c + dir; i++) {
                if (safe(rows, cols, r, i)) {
                    sol.push_back({r, i});
                }
            }
            c = c + dir;
            for (int i = r + 1; i <= r + dir; i++) {
                if (safe(rows, cols, i, c)) {
                    sol.push_back({i, c});
                }
            }
            r = r + dir;
            dir++;
            for (int i = c - 1; i >= c - dir; i--) {
                if (safe(rows, cols, r, i)) {
                    sol.push_back({r, i});
                }
            }
            c = c - dir;
            for (int i = r - 1; i >= r - dir; i--) {
                if (safe(rows, cols, i, c)) {
                    sol.push_back({i, c});
                }
            }
            r = r - dir;
            dir++;
        }
        return sol;
    }
};

int main() {
    vector<vector<int>> sol = Solution().spiralMatrixIII(5, 6, 1, 4);
    for (auto i : sol) {
        cout << i[0] << " " << i[1] << endl;
    }
    return 0;
}