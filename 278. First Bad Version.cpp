#include <bits/stdc++.h>
using namespace std;

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int l = 1, r = n;
        int sol = -1;
        while (l <= r) {
            long mid = ((long)l + (long)r) / 2;
            bool bad = isBadVersion(mid);
            if (bad) {
                sol = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return sol;
    }
};


int main() {
    int n;
    cin >> n;
    cout << Solution().firstBadVersion(n) << "\n";
    return 0;
}