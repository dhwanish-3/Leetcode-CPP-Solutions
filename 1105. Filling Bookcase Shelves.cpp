#include <bits/stdc++.h>
using namespace std;

class Solution {
    int rec(vector<vector<int>>& books, int w, int i, vector<int>& dp) {
        if (i == books.size()) return 0;
        if (dp[i] != -1) return dp[i];
        int curW = 0;
        int j = i;
        int maxH = 0;
        int sol = INT_MAX;
        while (j < books.size() && curW + books[j][0] <= w) {
            curW += books[j][0];
            maxH = max(maxH, books[j][1]);
            j++;
            sol = min(sol, maxH + rec(books, w, j, dp));
        }
        return dp[i] = sol;
    }
public:
    int minHeightShelves(vector<vector<int>>& books, int w) {
        int n = books.size();
        vector<int> dp(n, -1);
        return rec(books, w, 0, dp);
    }
};