#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m=board.size();
        int n=board[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int countOnes=0;
                for(int x=max(0,i-1);x<min(m,i+2);x++){
                    for(int y=max(0,j-1);y<min(n,j+2);y++){
                        countOnes+=board[x][y]&1;
                    }
                }
                if(board[i][j]==1 && (countOnes==3 || countOnes==4)){
                    board[i][j]|=0b10;
                    cout<<board[i][j]<<endl;
                }
                if(board[i][j]==0 && countOnes==3){
                    board[i][j]|=0b10;
                    cout<<board[i][j]<<endl;
                }
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                board[i][j]>>=1;
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
    Solution().gameOfLife(v);
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }    
    return 0;
}