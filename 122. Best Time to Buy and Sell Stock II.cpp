#include <bits/stdc++.h>
using namespace std;

class Solution {
    int recursion(vector<int>& arr, int i, bool buy) {
        if (i == arr.size()) {
            return 0;
        }
        if (buy) {
            return max(-arr[i] + recursion(arr, i + 1, !buy), recursion(arr, i + 1, buy));
        } else {
            return max(arr[i] + recursion(arr, i + 1, !buy), recursion(arr, i + 1, buy));
        }
    }
public:
    int maxProfit(vector<int>& arr) {
        int n = arr.size();
        vector<vector<int>> dp(n + 1, vector<int>(2, 0));
        for (int i = n - 1; i >= 0; i--) {
            dp[i][0] = max(-arr[i] + dp[i + 1][1], dp[i + 1][0]);
            dp[i][1] = max(arr[i] + dp[i + 1][0], dp[i + 1][1]);
        }
        int prevBuy = 0, prevSell = 0;
        for (int i = n - 1; i >= 0; i--) {
            prevSell = max(arr[i] + prevBuy, prevSell);
            prevBuy = max(-arr[i] + prevSell, prevBuy);
        }
        return prevBuy;
    }
};
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int buyPrice = 0;
        int sellPrice = 0;
        int Profit = 0;
        int i = 0;
        while (i < n - 1) {
            while (i < n - 1 && prices[i + 1] <= prices[i]) {
                i++;
            }
            buyPrice = prices[i];
            while (i < n - 1 && prices[i + 1] > prices[i]) {
                i++;
            }
            sellPrice = prices[i];
            Profit += (sellPrice - buyPrice);
        }
        return Profit;
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    cout << Solution().maxProfit(v);
    return 0;
}