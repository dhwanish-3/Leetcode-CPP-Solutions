#include <bits/stdc++.h>
using namespace std;

class Solution {
    int rec(vector<int>& nums1, vector<int>& nums2, int i, int j) {
        if (i == 0 || j == 0) {
            return 0;
        }
        int lines = 0;
        for (int k = j - 1; k >= 0; k--) {
            if (nums1[i - 1] == nums2[k]) 
                lines = max(lines, 1 + rec(nums1, nums2, i - 1, k));
        }
        lines = max(lines, rec(nums1, nums2, i - 1, j - 1));
        return lines;
    }
public:
    int func(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();
        return rec(nums1, nums2, n1, n2);
    }
};

int main() {
    vector<int> nums1 = {1, 4, 2};
    vector<int> nums2 = {1, 2, 4};
    cout << Solution().func(nums1, nums2) << endl;
}