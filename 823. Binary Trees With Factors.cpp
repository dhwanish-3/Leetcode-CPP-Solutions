#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        long sol = 0;
        long mod = 1e9 + 7;
        sort(arr.begin(), arr.end());
        unordered_map<int, long> dp;
        for (int i = 0; i < arr.size(); i++) {
            dp[arr[i]] = 1;
            for (int j = 0; j < i; j++) {
                if (arr[i] % arr[j] == 0) {
                    dp[arr[i]] = (dp[arr[i]] + dp[arr[j]] * dp[arr[i] / arr[j]]) % mod;
                }
            }
            sol = (sol + dp[arr[i]]) % mod;
        }
        return sol;
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n ; i++) {
        cin >> arr[i];
    }
    cout << Solution().numFactoredBinaryTrees(arr) << endl;
    return 0;
}