#include <bits/stdc++.h>
using namespace std;

// after decalring a vector with a particular size if you use push_back it will add the element to the nth index i.e. the back of the vector

class Solution {
public:
    // works only for small values of n (n<5) & grid[i][j] because stoi function reaches it's limit: integer out of range
    // int equalPairs(vector<vector<int>>& grid) {
    //     int n=grid.size();
    //     vector<int> rowString;
    //     vector<int> columnString;
    //     for(int i=0;i<n;i++){
    //         string row,col;
    //         for(int j=0;j<n;j++){
    //             row.append(to_string(grid[i][j]));
    //             row.append("0");
    //             col.append(to_string(grid[j][i]));
    //             col.append("0");
    //         }
    //         rowString.push_back(stoi(row));
    //         columnString.push_back(stoi(col));
    //     }
    //     int count=0;
    //     for(int i=0;i<n;i++){
    //         for(int j=0;j<n;j++){
    //             if(rowString[i]==columnString[j]) count++;
    //         }
    //     }
    //     return count;
    // }
    int equalPairs(vector<vector<int>>& grid) {
        int n=grid.size();
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                int k;
                for(k=0;k<n;k++){
                    if(grid[i][k]!=grid[k][j]) break;
                }
                if(k==n) count++;
            }
        }
        return count;
    }
};

int main(){
    int n,in;
    vector<vector<int>> vctr;
    cin>>n;
    for(int i=0;i<n;i++){
        vector<int> v;
        for(int j=0;j<n;j++){
            cin>>in;
            v.push_back(in);
        }
        vctr.push_back(v);
    }
    cout<<Solution().equalPairs(vctr);
    return 0;
}