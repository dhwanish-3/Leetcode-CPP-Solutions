#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxCoins(vector<int>& piles) {
        int n = piles.size();
        sort(piles.begin(), piles.end());
        int sol = 0;
        for (int j = n - 2; j >= n / 3; j -= 2) {
            sol += piles[j];
        }
        return sol;
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> piles(n);
    for (int i = 0; i < n; i++) {
        cin >> piles[i];
    }
    cout << Solution().maxCoins(piles) << endl;
    return 0;
}