#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        vector<int> bits(10001, 0);
        for (int i = 1; i <= 10000; i++) {
            bits[i] = bits[i >> 1] + (i & 1);
        }
        sort(arr.begin(), arr.end(), [&](int x, int y) {
            if (bits[x] < bits[y]) {
                return true;
            }
            if (bits[x] > bits[y]) {
                return false;
            }
            return x < y;
        });
        return arr;
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n ; i++) {
        cin >> arr[i];
    }
    vector<int> ans = Solution().sortByBits(arr);
    for (int i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }
    return 0;
}