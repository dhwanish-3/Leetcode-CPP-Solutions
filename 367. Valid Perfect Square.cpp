#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPerfectSquare(int num) {
        unsigned l = 1u;
        unsigned r = num + 1u;
        while (l < r) {
            unsigned m = (l + r) / 2;
            if (m * m == num) {
                return  true;
            } else if (m > num / m) {
                r = m;
            } else {
                l = m + 1;
            }
        }
        return false;
    }
};

int main() {
    int n;
    cin >> n;
    cout << Solution().isPerfectSquare(n) << "\n";
    return 0;
}