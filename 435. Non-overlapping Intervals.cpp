#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (intervals.empty()) {
            return 0;
        }
        int n = intervals.size();
        int sol = 0;
        sort(intervals.begin(),intervals.end(),[](const auto& a, const auto& b) { return a[1]<b[1]; });
        int maxTilNow = intervals[0][1];
        int i = 1;
        while (i<n) {
            if (maxTilNow <= intervals[i][0]) {
                maxTilNow = intervals[i][1];
            } else {
                sol++;
            }
            i++;
        }
        return sol;
    }
};

int main(){
    int n;
    cin>>n;
    vector<vector<int>> v(n, vector<int>(2));
    for (int i=0 ; i<n ; i++) {
        cin>>v[i][0]>>v[i][1];
    }
    cout<<Solution().eraseOverlapIntervals(v);
    return 0;
}