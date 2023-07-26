#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size();
        int n = image[0].size();
        queue<pair<int, int>> q{{{sr, sc}}};
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        vector<int> dirs{0, 1, 0 , -1, 0};
        int oldColor = image[sr][sc];
        image[sr][sc] = color;
        while (!q.empty()) {
            int i = q.front().first;
            int j = q.front().second;
            q.pop();
            for (int k = 0; k < 4; k++) {
                int x = i + dirs[k];
                int y = j + dirs[k + 1];
                if (x < 0 || x >= m || y < 0 || y >= n) {
                    continue;
                }
                if (visited[x][y] || image[x][y] != oldColor) {
                    continue;
                }
                image[x][y] = color;
                visited[x][y] = true;
                q.emplace(x, y);
            }
        }
        return image;
    }
};

int main(){
    vector<vector<int>> image = {{1,1,1},{1,1,0},{1,0,1}};
    vector<vector<int>> sol = Solution().floodFill(image, 1, 1, 2);
    for (int i = 0; i < sol.size(); i++) {
        for (int j = 0; j < sol[0].size(); j++) {
            cout<<sol[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}