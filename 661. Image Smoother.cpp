#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int m = img.size();
        int n = img[0].size();
        vector<vector<int>> sol(m, vector<int>(n));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++){
                int sum = 0;
                int count = 0;
                for (int k = i - 1; k <= i + 1; k++) {
                    for (int l = j - 1; l <= j + 1; l++){
                        if (k >= 0 && k < m && l >= 0 && l < n) {
                            sum += img[k][l];
                            count++;
                        }
                    }
                }
                sol[i][j] = sum / count;
            }
        }
        return sol;
    }
};

int main() {
    int m, n;
    cin >> m >> n;
    vector<vector<int>> img(m, vector<int>(n));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++){
            cin >> img[i][j];
        }
    }
    vector<vector<int>> sol = Solution().imageSmoother(img);
    for (int i = 0; i < sol.size(); i++) {
        for (int j = 0; j < sol[i].size(); j++){
            cout << sol[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}