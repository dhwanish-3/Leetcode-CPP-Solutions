#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> v;
        for(int i=0;i<numRows;i++){
            v.push_back(vector<int>(i+1,1));
        }
        for(int i=2;i<numRows;i++){
            for(int j=1;j<v[i].size()-1;j++){
                v[i][j]=v[i-1][j]+v[i-1][j-1];
            }
        }
        return v;
    }
};

int main(){
    int n;
    cin>>n;
    vector<vector<int>> v=Solution().generate(n);
    for(int i=0;i<v.size();i++){
        for(int j=0;j<v[i].size();j++){
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}