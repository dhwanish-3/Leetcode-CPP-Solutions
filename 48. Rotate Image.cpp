#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int i = 0;
        int last = n - 1;
        int temp = 0;
        int size = n;
        while (i < n / 2) {
            for (int j = i; j < size - 1; j++) {
                temp = matrix[i][j];
                last = n - j - 1;
                matrix[i][j] = matrix[last][i];
                matrix[last][i] = matrix[n - i - 1][last];
                matrix[n - i -1][last] = matrix[j][n - i - 1];
                matrix[j][n - i - 1] = temp;
            }
            i++;
            size--;
        }
    }
};

int main(){
    int n;
    cin>>n;
    vector<vector<int>> v(n,vector<int>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>v[i][j];
        }
    }
    Solution().rotate(v);
    return 0;
}