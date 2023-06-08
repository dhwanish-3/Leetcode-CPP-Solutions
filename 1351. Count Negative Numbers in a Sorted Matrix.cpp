#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int negNums=0;
        for(int i=0;i<grid.size();i++){
            negNums+=upper_bound(grid[i].rbegin(),grid[i].rend(),-1)-grid[i].rbegin();
        }
        return negNums;
    }
};

int main(){
    int m,n,in;
    cin>>m>>n;
    vector<vector<int>> grid;
    for(int i=0;i<m;i++){
        vector<int> v;
        for(int j=0;j<n;j++){
            cin>>in;
            v.push_back(in);
        }
        grid.push_back(v);
    }
    cout<<Solution().countNegatives(grid);
    return 0;
}