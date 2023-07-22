#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double knightProbability(int n, int k, int row, int column) {
        const double kProb = 0.125;
        const vector<pair<int, int>> dirs{{-2, 1}, {-1, 2}, {1, 2}, {2,1},
                                        {2, -1}, {1, -2}, {-1, -2}, {-2, -1}};
        vector<vector<double>> dp(n, vector<double> (n));
        // dp[i][j] = probability to stand on (i, j)
        dp[row][column] = 1.0;
        for (int q=0 ; q<k ; q++) {
            vector<vector<double>> newDp(n, vector<double>(n));
            for (int i=0 ; i<n ;  i++) {
                for (int j=0 ; j<n ; j++) {
                    if (dp[i][j] > 0.0) {
                        for (int d=0 ; d<8 ; d++) {
                            auto& dx = dirs[d].first;
                            auto& dy = dirs[d].second;
                            int x = i + dx;
                            int y = j + dy;
                            if (x<0 || x>=n || y<0 || y>=n) {
                                continue;
                            }
                            newDp[x][y] += dp[i][j] * kProb;
                        }
                    }
                }
            }
            dp = move(newDp);
        }
        double sol = accumulate(dp.begin(), dp.end(), 0.0, 
                    [](double s, vector<double>& row) {
                        return s += accumulate(row.begin(), row.end(), 0.0);
                    });
        return sol;
    }
};

int main(){
    int n, k ,r, c;
    cin>>n>>k>>r>>c;
    cout<<Solution().knightProbability(n, k, r, c);
    
    return 0;
}