#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> set;
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int n1 = nums1.size();
        int n2 = nums2.size();
        int i = 0, j = 0;
        while (i < n1 && j < n2) {
            if (nums1[i] == nums2[j]) {
                set.insert(nums1[i]);
                i++;
                j++;
            } else if (nums1[i] < nums2[j]) {
                i++;
            } else {
                j++;
            }
        }
        vector<int> sol;
        for (auto it : set) {
            cout << it << " ";
            sol.push_back(it);
        }
        return sol;
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
    vector<int> sol = Solution().intersection(nums1, nums2);
    for (auto it : sol) {
        cout << it << " ";
    }
    return 0;
}