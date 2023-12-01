#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfWays(string corridor) {
        int mod = 1e9 + 7;
        vector<int> pos;
        for (int i = 0; i < corridor.size(); i++) {
            if (corridor[i] == 'S') {
                pos.push_back(i);
            }
        }
        int n = pos.size();
        if (n % 2 == 1 || n == 0) {
            return 0;
        }
        long long sol = 1;
        int prev = pos[1];
        for (int i = 2; i < n; i += 2) {
            sol = (sol * (pos[i] - prev)) % mod;
            prev = pos[i + 1];
        }
        return sol;
    }
};

int main() {
    string corridor;
    cin >> corridor;
    cout << Solution().numberOfWays(corridor);
    return 0;
}