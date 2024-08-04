#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        unsigned l = 1;
        unsigned r = x + 1u;
        while (l < r) {
            unsigned m = (l + r) / 2;
            if (m > x / m) {
                r = m;
            } else {
                l = m + 1;
            }
        }
        return l - 1;
    }
};

int main() {
    int n;
    cin >> n;
    cout << Solution().mySqrt(n);
    return 0;
}