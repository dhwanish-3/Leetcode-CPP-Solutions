#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.empty()) {
            return {-1, -1};
        }
        int n = nums.size();
        int l = 0;
        int r = n - 1;
        int index = -1;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (nums[mid] == target) {
                index = mid;
                break;
            } else if (nums[mid] > target) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        if (index == -1) {
            return {-1, -1};
        }
        int start = index;
        int end = index;
        while (start > 0 && target == nums[start - 1]) {
            start--;
        }
        while (end + 1 < n && target == nums[end + 1]) {
            end++;
        }
        return {start, end};
    }
};

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0, r = n - 1;
        int left = -1, right = -1;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (nums[mid] < target) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
            if (nums[mid] == target) {
                left = mid;
            }
        }
        if (left == -1)
            return {left, right};
        right = left;
        l = left, r = n - 1;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (nums[mid] <= target) {
                l = mid + 1;
            } else {
                r = mid -1;
            }
            if (nums[mid] == target) {
                right = mid;
            }
        }
        return {left, right};
    }
};

int main(){
    int n, target;
    cin >> n >> target;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    vector<int> sol = Solution().searchRange(nums, target);
    for (int i = 0; i < sol.size(); i++) {
        cout << sol[i] << " ";
    }
    return 0;
}