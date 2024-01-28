#include <bits/stdc++.h>
using namespace std;

class Solution {
    int recursion(int m, int n, int maxMove, int startRow, int startColumn, vector<vector<vector<int>>>& dp) {
        if (startRow < 0 || startRow >= m || startColumn < 0 || startColumn >= n) {
            return 1;
        }
        if (maxMove == 0) {
            return 0;
        }
        if (dp[startRow][startColumn][maxMove] != -1) {
            return dp[startRow][startColumn][maxMove];
        }
        int sol = 0;
        sol = (sol + recursion(m, n, maxMove - 1, startRow - 1, startColumn, dp)) % 1000000007;
        sol = (sol + recursion(m, n, maxMove - 1, startRow + 1, startColumn, dp)) % 1000000007;
        sol = (sol + recursion(m, n, maxMove - 1, startRow, startColumn - 1, dp)) % 1000000007;
        sol = (sol + recursion(m, n, maxMove - 1, startRow, startColumn + 1, dp)) % 1000000007;
        return dp[startRow][startColumn][maxMove] = sol;
    }
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(maxMove + 1, -1)));
        return recursion(m, n, maxMove, startRow, startColumn, dp);
    }
};

int main() {
    int m, n, maxMove, startRow, startColumn;
    cin >> m >> n >> maxMove >> startRow >> startColumn;
    cout << Solution().findPaths(m, n, maxMove, startRow, startColumn) << endl;
    return 0;
}