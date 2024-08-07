#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int arrangeCoins(int n) {
        int sol = 1;
        while (n > 0) {
            n = n - sol - 1;
            sol++;
        }
        return sol - 1;
    }
};

int main() {
    int n;
    cin >> n;
    cout << Solution().arrangeCoins(n) << "\n";
    return 0;
}