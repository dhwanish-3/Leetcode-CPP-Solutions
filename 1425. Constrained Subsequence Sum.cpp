#include <bits/stdc++.h>
using namespace std;

// Approach 1: DP - Tabulation - Memory Limit Exceeded
class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> dp(n, 0);
        int sol = INT_MIN;
        for (int i = 0; i < n; i++) {
            dp[i] = nums[i];
            for (int j = i - 1; j >= 0 && j >= i - k; j--) {
                dp[i] = max(dp[i], dp[j] + nums[i]);
            }
            sol = max(sol, dp[i]);
        }
        return sol;  
    }
};

// Approach 2: MaxHeap
class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        int n = nums.size();
        int maxSum = nums[0];
        deque<pair<int,int>> dp;
        dp.push_back({0, nums[0]});
        for (int i = 1; i < n; i++) {
            if (i - dp.front().first > k) {
                dp.pop_front();
            }
            int current = nums[i];
            if (dp.front().second > 0) {
                current += dp.front().second;
            }
            maxSum = max(maxSum, current);
            while (!dp.empty() && dp.back().second < current) {
                dp.pop_back();
            }
            dp.push_back({i, current});
        }
        return maxSum;
    }
};

class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        
        int n = nums.size();
        int maxSum = nums[0];
        deque<pair<int,int>> dp;
        dp.push_back({0, nums[0]});

        for(int i = 1; i < n; i++)
        {
            if(i - dp.front().first > k)
                dp.pop_front();
            
            int current = nums[i];
            if(dp.front().second > 0)
                current += dp.front().second;
            maxSum = max(current, maxSum);

            while(!dp.empty() && dp.back().second < current)
                dp.pop_back();

            dp.push_back({i, current});
        }

        return maxSum;
    }
};

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    cout << Solution().constrainedSubsetSum(v, k) << endl;
    return 0;
}