#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findPivot(vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = n - 1;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (nums[mid] > nums[n - 1]) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return l;
    }
    int binarySearch(vector<int>& nums, int target, int pivot) {
        int n = nums.size();
        int l = 0, r = n - 1;
        while (l <= r) {
            int mid = (l + r) / 2;
            int check = (mid + pivot) % n;
            if (nums[check] == target) {
                return check;
            } else if (nums[check] > target) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        int pivot = findPivot(nums);
        return binarySearch(nums, target, pivot);
    }
};

int main() {
    // vector<int> arr = {4,5, 6, 7, 0,1,2};
    // vector<int> arr = {4,5, 6, 0,1,2};
    vector<int> arr = {4,5, 6,7,8, -4, -3 , -2, 0,1,2};
    cout << Solution().findPivot(arr) << endl;
    cout << Solution().search(arr, 6) << endl;
    cout << Solution().search(arr, 1) << endl;
    cout << Solution().search(arr, -5) << endl;
    cout << Solution().search(arr, 8) << endl;
    return 0;
}