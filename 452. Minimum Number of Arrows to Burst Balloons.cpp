#include <bits/stdc++.h>
using namespace std;

class Solution {
    static bool compare(const vector<int>& a, const vector<int>& b) {
        return a[1] < b[1];
    }
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), compare);
        int select = points[0][1];
        int arrows = 1;
        for (int i = 1; i < points.size(); i++) {
            if (points[i][0] > select) {
                arrows++;
                select = points[i][1];
            }
        }
        return arrows;
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