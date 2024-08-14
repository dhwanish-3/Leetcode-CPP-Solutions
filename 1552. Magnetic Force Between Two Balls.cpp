#include <bits/stdc++.h>
using namespace std;

class Solution {
    bool check(vector<int>& position, int mid, int m) {
        int lastBallAt = position[0];
        int ballsLeft = m - 1;
        for (int i = 1; ballsLeft > 0 && i < position.size();) {
            if (position[i] - lastBallAt < mid) {
                i++;
            } else {
                lastBallAt = position[i];
                ballsLeft--;
            }
        }
        return ballsLeft == 0;
    }
public:
    int maxDistance(vector<int>& position, int m) {
        int l = 1, r = 1e9;
        sort(position.begin(), position.end());
        while (l < r) {
            int mid = (l + r + 1) / 2;
            if (check(position, mid, m)) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }
        return l;
    }
};