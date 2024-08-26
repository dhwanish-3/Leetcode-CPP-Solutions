#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        int l = 0, r = n - 1;
        while (l <= r) {
            int mid = (l + r) / 2;
            int citation = n - mid;
            if (citation > citations[mid]) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return n - l;
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    cout << Solution().hIndex(nums) << "\n";
    return 0;
}