#include <bits/stdc++.h>
using namespace std;

class Solution {
    int count = 0;
    vector<bool> seen;
    void rec(int n, int i) {
        if (i > n) {
            count++;
            return;
        }
        for (int j = 1; j <= n; j++) {
            if (!seen[j] && (j % i == 0 || i % j == 0)) {
                seen[j] = true;
                rec(n, i + 1);
                seen[j] = false;
            }
        }
    }
public:
    int countArrangement(int n) {
        seen.resize(16, false);
        rec(n, 1);
        return count;
    }
};