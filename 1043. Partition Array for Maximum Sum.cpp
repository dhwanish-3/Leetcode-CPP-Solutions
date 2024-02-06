#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n + 1);
        for (int i = 1; i <= n; i++) {
            int maxVal = 0;
            for (int j = 1; j <= k && i - j >= 0; j++) {
                maxVal = max(maxVal, arr[i - j]);
                dp[i] = max(dp[i], dp[i - j] + maxVal * j);
            }
        }
        return dp[n];
    }
};

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << Solution().maxSumAfterPartitioning(arr, k);
    return 0;
}