#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        int l = 0;
        int r = n - 1;
        while (l <= r) {
            int mid = (l + r) / 2;
            int leftMid = mid - 1 >= 0 ? nums[mid - 1] : INT_MIN;
            int rightMid = mid + 1 < n ? nums[mid + 1] : INT_MIN;
            if (leftMid < nums[mid] && rightMid < nums[mid]) {
                return mid;
            } else if (leftMid > nums[mid]) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return 0;
    }
};

int main(){
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    cout << Solution().findPeakElement(nums);
    return 0;
}