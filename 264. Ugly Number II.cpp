#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int nthUglyNumber(int n) {
        if (n == 1) return 1;
        int t2 = 0, t3 = 0, t5 = 0;
        vector<int> cur(n, 0);
        cur[0] = 1;
        for (int i = 1; i < n; i++) {
            cur[i] = min({cur[t2] * 2, cur[t3] * 3, cur[t5] * 5});
            if (cur[i] == cur[t2] * 2) t2++;
            if (cur[i] == cur[t3] * 3) t3++;
            if (cur[i] == cur[t5] * 5) t5++;
        }
        return cur[n - 1];
    }
};