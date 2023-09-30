#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        stack<int> s;
        int thirdNum = INT_MIN;
        for (int i = nums.size() - 1; i >= 0; i--) {
            if (nums[i] < thirdNum) {
                return true;
            }
            while (!s.empty() && s.top() < nums[i]) {
                thirdNum = s.top();
                s.pop();
            }
            s.push(nums[i]);
        }
        return false;
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int &i : nums) {
        cin >> i;
    }
    cout << (new Solution())->find132pattern(nums) << endl;
    return 0;
}