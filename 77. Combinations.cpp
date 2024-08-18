#include <bits/stdc++.h>
using namespace std;

// Approach 1: Recursive
class Solution {
    vector<vector<int>> sol;
    void rec(int n, int i, int k, vector<int>& cur) {
        if (k == cur.size()) {
            sol.push_back(cur);
            return;
        }
        for (int j = i + 1; j <= n; j++) {
            cur.push_back(j);
            rec(n, j, k, cur);
            cur.pop_back();
        }
    }
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> cur;
        rec(n, 0, k, cur);
        return sol;
    }
};

// Approch 2: Iterative
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> sol;
        vector<int> temp(k, 0);
        int i = 0;
        while ( i >= 0) {
            temp[i]++;
            if (temp[i] > n) {
                i--;
            } else if (i == k - 1) {
                sol.push_back(temp);
            } else {
                i++;
                temp[i] = temp[i - 1];
            }
        }
        return sol;
    }
};

int main(){
    int n, k;
    cin >> n >> k;
    vector<vector<int>> sol = Solution().combine(n, k);
    for (int i = 0; i < sol.size(); i++) {
        for (int j = 0; j < sol[i].size(); j++) {
            cout << sol[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}