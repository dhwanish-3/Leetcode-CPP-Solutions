#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> cost(n, 1e8);
        cost[src] = 0;
        for (int z = 0; z <= k; z++) {
            vector<int> temp(cost);
            for (auto flight : flights) {
                temp[flight[1]] = min(temp[flight[1]], cost[flight[0]] + flight[2]);
            }
            cost = temp;
        }
        return cost[dst] == 1e8 ? -1 : cost[dst];
    }
};

int main() {
    int m, n, src, dst, k;
    cin >> m >> n >> src >> dst >> k;
    vector<vector<int>> flights(m, vector<int>(3));
    for (int i = 0; i < m; i++) {
        cin >> flights[i][0] >> flights[i][1] >> flights[i][2];
    }
    cout << Solution().findCheapestPrice(n, flights, src, dst, k);
    return 0;
}