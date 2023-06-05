#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        int n=coordinates.size();
        if(n==2) return true;
        double delY=coordinates[1][1]-coordinates[0][1];
        double delX=coordinates[1][0]-coordinates[0][0];
        double slope=delY/delX;
        double m;
        for(int i=2;i<n;i++){
            delY=coordinates[i][1]-coordinates[0][1];
            delX=coordinates[i][0]-coordinates[0][0];
            m=delY/delX;
            cout<<m<<" "<<slope<<endl;
            if(m!=slope) return false;
        }
        return true;
    }
};

int main(){
    vector<vector<int>> cd;
    int n,a,b;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a>>b;
        vector<int> vctr;
        vctr.push_back(a);
        vctr.push_back(b);
        cd.push_back(vctr);
    }
    cout<<Solution().checkStraightLine(cd);
    return 0;
}