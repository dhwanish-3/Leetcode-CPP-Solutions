#include <bits/stdc++.h>
using namespace std;

// Approach 1: DP - Naive
class Solution {
public:
    vector<int> countBits(int n) {
        if (n == 0) {
            return {0};
        }
        vector<int> sol(n + 1, 0);
        sol[1] = 1;
        int i = 2;
        while (i <= n) {
            int end = i;
            for (int j = 0; j < end && i <= n; j++) {
                sol[i] = 1 + sol[j];
                i++;
            }
        }
        return sol;
    }
};

// Approach 2: DP - Optimized
class Solution {
public:
    vector<int> countBits(int n) {
        if (n == 0) {
            return {0};
        }
        vector<int> sol(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            sol[i] = sol[i / 2] + i % 2;
        }
        return sol;
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> sol = Solution().countBits(n);
    for (int i = 0; i < sol.size(); i++) {
        cout << sol[i] << " ";
    }
    return 0;
}