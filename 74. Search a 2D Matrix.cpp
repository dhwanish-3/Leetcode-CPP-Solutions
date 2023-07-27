#include <bits/stdc++.h>
using namespace std;

// Approach 1: Matrix Search
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int l = 0;
        int r = n - 1;
        while (l < m && r >= 0) {
            if (matrix[l][r] == target) {
                return true;
            } else if (matrix[l][r] > target) {
                r--;
            } else {
                l++;
            }
        }
        return false;
    }
};

// Approach 2: Binary Search
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int l = 0;
        int r = m * n - 1;
        while (l <= r) {
            int mid = (l + r) / 2;
            int midValue = matrix[mid / n][mid % n];
            if (midValue == target) {
                return true;
            } else if (midValue > target) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return false;
    }
};

int main(){
    int m, n;
    cin >> m >> n;
    vector<vector<int>> matrix(m, vector<int>(n));
    for (int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }
    int target;
    cin >> target;
    cout << Solution().searchMatrix(matrix, target);
    return 0;
}