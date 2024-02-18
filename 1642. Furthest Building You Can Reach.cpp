#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int n = heights.size();
        priority_queue<int> maxBricks;
        int i = 0;
        for (i = 0; i < n - 1; i++) {
            if (heights[i + 1] - heights[i] > 0) {
                bricks -= (heights[i + 1] - heights[i]);
                maxBricks.push(heights[i + 1] - heights[i]);
                if (bricks < 0) {
                    bricks += maxBricks.top();
                    maxBricks.pop();
                    ladders--;
                }
                if (ladders < 0) {
                    break;
                }
            }
        }
        return i;
    }
};

int main() {
    int n, bricks, ladders;
    cin >> n >> bricks >> ladders;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    cout << Solution().furthestBuilding(v, bricks, ladders);
    return 0;
}