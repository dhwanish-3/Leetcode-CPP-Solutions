#include <bits/stdc++.h>
using namespace std;

class Solution {
    int recursion(vector<int>& nums1, vector<int>& nums2, int i, int j, vector<vector<int>>& dp) {
        if (i == nums1.size() || j == nums2.size()) {
            return INT_MIN;
        }
        if (dp[i][j] != INT_MIN) {
            return dp[i][j];
        }
        int choose = nums1[i] * nums2[j] + max(recursion(nums1, nums2, i + 1, j + 1, dp), 0);
        int no = max(recursion(nums1, nums2, i + 1, j, dp), recursion(nums1, nums2, i, j + 1, dp));
        return dp[i][j] = max(choose, no);
    }
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> dp(nums1.size(), vector<int>(nums2.size(), INT_MIN));
        return recursion(nums1, nums2, 0, 0, dp);
    }
};

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> v1(n), v2(m);
    for (int i = 0; i < n; i++) {
        cin >> v1[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> v2[i];
    }
    cout << Solution().maxDotProduct(v1, v2) << endl;
    return 0;
}