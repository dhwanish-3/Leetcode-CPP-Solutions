#include <bits/stdc++.h>
using namespace std;

static bool compare(const string& a, const string& b) {
    if (a.length() != b.length()) {
        return a.length() > b.length();
    }
    if (a == b) {
        return false;
    }
    int i = 0;
    while (a[i] == b[i]) {
        i++;
    }
    return a[i] > b[i];
}
class Solution {
public:
    string kthLargestNumber(vector<string>& nums, int k) {
        int n = nums.size();
        priority_queue<string, vector<string>, decltype(&compare)> q(&compare);
        for (int i = 0; i < k; i++) {
            q.push(nums[i]);
        }
        for (int i = k; i < n; i++) {
            if (compare(nums[i], q.top())) {
                q.pop();
                q.push(nums[i]);
            }
        }
        return q.top();
    }
};

int main() {
    int n, k;
    cin >> n >> k;
    vector<string> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    cout << Solution().kthLargestNumber(nums, k);
    return 0;
}