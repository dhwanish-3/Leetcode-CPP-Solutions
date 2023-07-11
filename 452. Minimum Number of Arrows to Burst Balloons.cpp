#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end(),[](const auto& a, const auto& b) { return  a[1] < b[1];});
        int sol = 1;
        int arrowX = points[0][1];
        for (int i=1; i<points.size(); i++) {
            if(points[i][0] > arrowX) {
                arrowX = points[i][1];
                sol++;
            }
        }
        return sol;
    }
};

int main(){
    int n;
    cin>>n;
    vector<vector<int>> v(n, vector<int> (2));
    for ( int i=0; i<n; i++) {
        cin>>v[i][0]>>v[i][1];
    }
    cout<<Solution().findMinArrowShots(v);
    return 0;
}