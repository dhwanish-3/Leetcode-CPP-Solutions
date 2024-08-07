#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n = score.size();
        vector<int> indices(n, 0);
        for (int i = 0; i < n; i++) {
            indices[i] = i;
        }
        sort(indices.begin(), indices.end(), [&](int a, int b) {
            return score[a] > score[b];
        });
        vector<string> sol(n);
        for (int i = 0; i < n; i++) {
            if (i == 0) {
                sol[indices[i]] = "Gold Medal";
            } else if (i == 1) {
                sol[indices[i]] = "Silver Medal";
            } else if (i == 2) {
                sol[indices[i]] = "Bronze Medal";
            } else {
                sol[indices[i]] = to_string(i + 1);
            }
        }
        return sol;
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> score(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> score[i];
    }
    vector<string> sol = Solution().findRelativeRanks(score);
    for (int i = 0; i < n; i++) {
        cout << sol[i] << "\n";
    }
    return 0;
}