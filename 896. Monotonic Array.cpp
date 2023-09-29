#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        while (i + 1 < n && nums[i] == nums[i + 1]) {
            i++;
        }
        if (i + 1 >= n) {
            return true;
        }
        bool decreasing = nums[i + 1] < nums[i];
        while (i + 1 < n) {
            if (nums[i + 1] > nums[i] && decreasing) {
                return false;
            }
            if (nums[i + 1] < nums[i] && !decreasing) {
                return false;
            }
            i++;
        }
        return true;
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    cout << Solution().isMonotonic(v) << endl;
    return 0;
}