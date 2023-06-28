#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> spiral;
        int m=matrix.size();
        int n=matrix[0].size();
        int toRight=0;
        int toLeft=n-1;
        int toDown=0;
        int toUp=m-1;
        while(spiral.size()<m*n){
            for(int i=toRight;i<=toLeft && spiral.size()<m*n;i++){
                spiral.push_back(matrix[toDown][i]);
            }
            for(int i=toDown+1;i<=toUp-1 && spiral.size()<m*n;i++){
                spiral.push_back(matrix[i][toLeft]);
            }
            for(int i=toLeft;i>=toRight && spiral.size()<m*n;i--){
                spiral.push_back(matrix[toUp][i]);
            }
            for(int i=toUp-1;i>=toDown+1 && spiral.size()<m*n;i--){
                spiral.push_back(matrix[i][toRight]);
            }
            toRight++;
            toLeft--;
            toDown++;
            toUp--;
        }
        return spiral;
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
    vector<int> sol=Solution().spiralOrder(v);
    for(int i=0;i<sol.size();i++) cout<<sol[i]<<" ";
    return 0;
}