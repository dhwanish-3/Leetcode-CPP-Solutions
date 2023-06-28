#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        vector<int> row;
        vector<int> column;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]==0){
                    row.push_back(i);
                    column.push_back(j);
                }
            }
        }
        for(int i=0;i<row.size();i++){
            for(int j=0;j<n;j++){
                matrix[row[i]][j]=0;
            }
        }
        for(int i=0;i<column.size();i++){
            for(int j=0;j<m;j++){
                matrix[j][column[i]]=0;
            }
        }
    }
};

int main(){
    int m,n;
    cin>>m>>n;
    vector<vector<int>> v(m,vector<int>(n));
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>v[i][j];
        }
    }
    Solution().setZeroes(v);
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}