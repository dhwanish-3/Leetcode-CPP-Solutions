#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(), tokens.end());
        int n = tokens.size();
        int l = 0, r = n - 1;
        int sol = 0, score = 0;
        while (l <= r) {
            if (power >= tokens[l]) {
                power -= tokens[l];
                l++;
                score++;
                sol = max(sol, score);
            } else if (sol > 0) {
                power += tokens[r];
                r--;
                score--;
            } else {
                break;
            }
        }
        return sol;
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> tokens(n);
    for (int i = 0; i < n; i++) {
        cin >> tokens[i];
    }
    int power;
    cin >> power;
    cout << Solution().bagOfTokensScore(tokens, power);
    return 0;
}