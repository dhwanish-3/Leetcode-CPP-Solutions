#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPathCrossing(string path) {
        set<pair<int, int>> points;
        points.insert(make_pair(0, 0));
        int x = 0, y = 0;
        for (int i = 0; i < path.length(); i++) {
            if (path[i] == 'N') {
                y++;
            } else if (path[i] == 'S') {
                y--;
            } else if (path[i] == 'E') {
                x++;
            } else if (path[i] == 'W') {
                x--;
            }
            if (points.count(make_pair(x, y))) {
                return true;
            }
            points.insert(make_pair(x, y));
        }
        return false;
    }
};

int main() {
    string s;
    cin >> s;
    cout << Solution().isPathCrossing(s);
    return 0;
}