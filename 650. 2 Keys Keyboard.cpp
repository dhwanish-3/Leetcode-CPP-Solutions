#include <bits/stdc++.h>
using namespace std;

class Solution {
    int rec(int n, int count, int copied) {
        if (count > n) {
            return 1e9;
        }
        if (count == n) {
            return 0;
        }
        int paste = 1 + rec(n, count + copied, copied);
        int copy = count == copied ? INT_MAX : 1 + rec(n, count, count);
        return min(paste, copy);
    }
public:
    int minSteps(int n) {
        vector<int> dp(n + 1, 0);
        for (int count = 2; count <= n; count++) {
            dp[count] = count;
            for (int copied = count - 1; copied > 1; copied--) {
                if (count % copied == 0) {
                    dp[count] = dp[copied] + (count / copied);
                    break;
                }
            }
        }
        return dp[n];
    }
};

int main() {
    int n;
    cin >> n;
    cout << Solution().minSteps(n);
    return 0;
}