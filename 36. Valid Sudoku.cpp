#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0;i<9;i++){
            vector<bool> visitedx(10,false);
            for(int j=0;j<9;j++){
                if(board[i][j]=='.') continue;
                if(visitedx[board[i][j]-'0']) return false;
                visitedx[board[i][j]-'0']=true;
            }
            vector<bool> visitedy(10,false);
            for(int j=0;j<9;j++){
                if(board[j][i]=='.') continue;
                if(visitedy[board[j][i]-'0']) return false;
                visitedy[board[j][i]-'0']=true;
            }
        }
        for(int i=0;i<9;i+=3){
            for(int j=0;j<9;j+=3){
                vector<bool> seen(10,false);
                for(int x=i;x<i+3;x++){
                    for(int y=j;y<j+3;y++){
                        if(board[x][y]=='.') continue;
                        if(seen[board[x][y]-'0']) return false;
                        seen[board[x][y]-'0']=true;
                    }
                }
            }
        }
        return true;
    }
};

int main(){
    vector<vector<char>> v(3,vector<char>(3));
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            cin>>v[i][j];
        }
    }
    cout<<Solution().isValidSudoku(v);
    // for(int i=0;i<9;i+=3){
    //     for(int j=0;j<9;j+=3){
    //         for(int x=i;x<i+3;x++){
    //             for(int y=j;y<j+3;y++){
    //                 cout<<x<<" "<<y<<endl;
    //             }
    //             cout<<endl;
    //         }
    //     }
    // }
    return 0;
}