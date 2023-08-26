#include <bits/stdc++.h>
using namespace std;

bool compare(vector<int> a, vector<int> b) {
    return a[1] < b[1];
}
class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int n = pairs.size();
        sort(pairs.begin(), pairs.end(), compare);
        int sol = 0;
        int prev = INT_MIN;
        for (int i = 0; i < n; i++) {
            if (pairs[i][0] > prev) {
                prev = pairs[i][1];
                sol++;
            }
        }
        return sol;
    }
};

int main() {
    int n;
    cin >> n;
    vector<vector<int>> pairs(n, vector<int>(2));
    for (int i = 0; i < n; i++) {
        cin >> pairs[i][0] >> pairs[i][1];
    }
    cout << Solution().findLongestChain(pairs);
    return 0;
}