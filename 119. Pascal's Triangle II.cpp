#include <bits/stdc++.h>
using namespace std;

// Approach 1: Space Complexity O(rowIndex^2)
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>> pascal(rowIndex + 1);
        for (int i = 0; i <= rowIndex; i++) {
            pascal[i] = vector<int>(i + 1, 1);
        }
        for (int i = 2; i <= rowIndex; i++) {
            for (int j = 1; j < i; j++) {
                pascal[i][j] = pascal[i - 1][j] + pascal[i - 1][j - 1];
            }
        }
        return pascal[rowIndex];
    }
};

// Approach 2: Space Complexity O(rowIndex)
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> pascal(rowIndex + 1, 1);
        for (int i = 2; i <= rowIndex; i++) {
            for (int j = i - 1; j >= 1; j--) {
                pascal[j] += pascal[j - 1];
            }
        }
        return pascal;
    }
};

int main(){
    int n;
    cin >> n;
    vector<int> ans = Solution().getRow(n);
    for (int& num : ans) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}