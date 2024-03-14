#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int i = 0, j = 0;
        int n1 = nums1.size(), n2 = nums2.size();
        while (i < n1 && j < n2) {
            if (nums1[i] == nums2[j]) {
                return nums1[i];
            } else if (nums1[i] < nums2[j]) {
                i++;
            } else {
                j++;
            }
        } 
        return -1;
    }
};

int main() {
    int n1, n2;
    cin >> n1 >> n2;
    vector<int> nums1(n1), nums2(n2);
    for (int i = 0; i < n1; i++) {
        cin >> nums1[i];
    }
    for (int i = 0; i < n2; i++) {
        cin >> nums2[i];
    }
    cout << Solution().getCommon(nums1, nums2);
    return 0;
}