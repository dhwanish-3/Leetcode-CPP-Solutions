#include <bits/stdc++.h>
using namespace std;

class Solution {
    vector<vector<int>> dp;
    int maximumValue(vector<vector<int>>& events, int i, int k) {
        if (k == 0 || i == events.size()) return 0;
        if (dp[i][k] != -1) return dp[i][k];
        // Binary search events to find the first index j such that events[j][0] > events[i][1]
        auto it = upper_bound(events.begin()+i, events.end(), events[i][1], [](int end, auto& a) {return a[0] > end;});
        int j = distance(events.begin(), it);
        return dp[i][k] = max(events[i][2] + maximumValue(events, j, k-1), maximumValue(events, i+1, k));
    }
public:
    int maxValue(vector<vector<int>>& events, int k) {
        // dp[i][k] = max sum of events[i:] with max k no. of elements
        int n = events.size();
        dp.resize(n, vector<int> (k + 1, -1));
        sort(events.begin(), events.end());
        return maximumValue(events, 0 , k);
    }
};

int main(){
    int n,k;
    cin>>n;
    vector<vector<int>> v(n, vector<int> (3));
    for ( int i=0 ; i<n ; i++) {
        cin>>v[i][0]>>v[i][1]>>v[i][2];
    }
    cin>>k;
    cout<<Solution().maxValue(v,k);
    return 0;
}