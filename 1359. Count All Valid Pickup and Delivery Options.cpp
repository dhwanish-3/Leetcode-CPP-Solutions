#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countOrders(int n) {
        int mod = 1e9 + 7;
        long long sol = 1;
        for (int i = 2; i <= n; i++) {
            sol = (sol * (2 * i - 1) * i) % mod;
        }
        return (int)sol;
    }
};

int main() {
    int n;
    cin >> n;
    cout << Solution().countOrders(n) << endl;
    return 0;
}