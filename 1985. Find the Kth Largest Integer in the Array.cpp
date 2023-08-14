#include <bits/stdc++.h>
using namespace std;

struct compare {
    bool operator() (const string& a, const string& b) {
        return stoi(a) > stoi(b);
    }
};
class Solution {
public:
    string kthLargestNumber(vector<string>& nums, int k) {
        int n = nums.size();
        priority_queue<string, vector<string>, compare> q;
        for (int i = 0; i < k; i++) {
            q.push(nums[i]);
        }
        for (int i = k; i < n; i++) {
            if (stoi(q.top()) < stoi(nums[i])) {
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