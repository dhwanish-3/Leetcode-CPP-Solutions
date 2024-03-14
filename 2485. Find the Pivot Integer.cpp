#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int pivotInteger(int n) {
        int sum = (n * (n + 1)) / 2;
        int cur = 0;
        for (int i  = 1; i <= n; i++) {
            cur += i;
            if (cur == sum - cur + i) {
                return i;
            } else if (cur > sum - cur + i) {
                break;
            }
        }
        return -1;
    }
};

int main() {
    int n;
    cin >> n;
    cout << Solution().pivotInteger(n);
    return 0;
}