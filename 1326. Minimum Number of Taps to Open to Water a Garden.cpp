#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        vector<int> jumps(n + 1, 0);
        int l = 0, r = 0;
        for (int i = 0; i < ranges.size(); i++) {
            l = max(0, i - ranges[i]);
            r = min(n, i + ranges[i]);
            jumps[l] = max(jumps[l], r - l);
        }
        int count = 0;
        int curEnd = 0;
        int curFarthest = 0;
        for (int i = 0; i < jumps.size() - 1; i++) {
            if (i > curFarthest) {
                return -1;
            }
            curFarthest = max(curFarthest, i + jumps[i]);
            if (i == curEnd) {
                count++;
                curEnd = curFarthest;
            }
        }
        return curFarthest >= n ? count : -1;
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> ranges;
    int range;
    for (int i = 0; i < n + 1; i++) {
        cin >> range;
        ranges.push_back(range);
    }
    cout << Solution().minTaps(n, ranges) << endl;
    return 0;
}