#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumOneBitOperations(int n) {
        if (n <= 1) {
            return n;
        }
        int sol = 0;
        while ( (1 << sol) <= n) {
            sol++;
        }
        return (1 << sol) - 1 - minimumOneBitOperations(n - (1 << (sol - 1)));
    }
};

int main() {
    int n;
    cin >> n;
    cout << Solution().minimumOneBitOperations(n);
    return 0;
}