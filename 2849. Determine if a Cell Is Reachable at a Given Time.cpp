#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        int x = abs(fx - sx);
        int y = abs(fy - sy);
        int minDistance = min(x, y) + abs(y - x);
        if (minDistance == 0) {
            if (t == 1) {
                return false;
            }
            return true;
        }
        return  minDistance <= t;
    }
};

int main() {
    int sx, sy, fx, fy, t;
    cin >> sx >> sy >> fx >> fy >> t;
    cout << (Solution().isReachableAtTime(sx, sy, fx, fy, t) ? "True" : "False") << endl;
    return 0;
}