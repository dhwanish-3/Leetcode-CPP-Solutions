#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int totalMoney(int n) {
        int sol = 0;
        for (int i = 0; i < n; i++) {
            sol += (i / 7) + (i % 7) + 1;
        }
        return sol;
    }
};

int main() {
    int n;
    cin >> n;
    cout << Solution().totalMoney(n);
    return 0;
}