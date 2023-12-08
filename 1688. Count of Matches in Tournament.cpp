#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfMatches(int n) {
        int sol = 0;
        while (n > 1) {
            sol += n / 2;
            n = (n + 1) / 2;
        }
        return sol;
    }
};

int main() {
    int n;
    cin >> n;
    cout << Solution().numberOfMatches(n);
    return 0;
}