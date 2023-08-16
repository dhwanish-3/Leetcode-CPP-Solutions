#include <bits/stdc++.h>
using namespace std;


// Approach 1: MaxHeap - TLE
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> sol;
        for (int i = 0; i <= n - k; i++) {
            priority_queue<int> maxHeap{nums.begin() + i, nums.begin() + i + k};
            sol.push_back(maxHeap.top());
        }
        return sol;
    }
};

// Approach 2: maxHeap - Optimized
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> sol;
        priority_queue<pair<int, int>> q;
        for (int i = 0; i < k; i++) {
            q.emplace(nums[i], i);
        }
        sol.push_back(q.top().first);
        for (int i = k; i < n; i++) {
            while (!q.empty() && q.top().second <= i - k) {
                q.pop();
            }
            q.emplace(nums[i], i);
            sol.push_back(q.top().first);
        }
        return sol;
    }
};

// Approach 3: Using Deque
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        deque<int> dq;
        vector<int> sol;
        for (int i = 0; i < n; i++) {
            while (!dq.empty() && dq.front() <= i - k) {
                dq.pop_front();
            }
            while (!dq.empty() && nums[dq.back()] <= nums[i]) {
                dq.pop_back();
            }
            dq.push_back(i);
            if (i >= k - 1) {
                sol.push_back(nums[dq.front()]);
            }
        }
        return sol;
    }
};

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> nums(n);
    for (int& x : nums) cin >> x;
    vector<int> sol = Solution().maxSlidingWindow(nums, k);
    for (int& x : sol) cout << x << " ";
    return 0;
}