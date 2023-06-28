#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size();
        for(int i=0;i<n/2;i++){
            int max=n-i-1;
            for(int j=i;j<max;j++){
                int offset=j-i;
                int top=matrix[i][j];
                matrix[i][j]=matrix[max-offset][i];
                matrix[max-offset][i]=matrix[max][max-offset];
                matrix[max][max-offset]=matrix[j][max];
                matrix[j][max]=top;
            }
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