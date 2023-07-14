#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        int n = arr.size();
        int sol = 1;
        unordered_map<int, int> dp;
        for (int i=0 ; i<n ; i++) {
            auto it = dp.find(arr[i] - difference);
            if (it != dp.end()) {
                dp[arr[i]] = it->second + 1;
            } else {
                dp[arr[i]] = 1;
            }
            sol = max (sol, dp[arr[i]]);
        }
        return sol;
    }
};

int main(){
    int n, k;
    cin>>n;
    vector<int> v(n);
    for (int i=0; i<n; i++) cin>>v[i];
    cin>>k;
    cout<<Solution().longestSubsequence(v,k);
    return 0;
}