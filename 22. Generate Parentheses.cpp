#include <bits/stdc++.h>
using namespace std;

class Solution {
    void dfs(int l, int r, string&& path, vector<string>& sol) {
        if (l == 0 && r == 0) {
            sol.push_back(path);
            return;
        }
        if (l > 0) {
            path.push_back('(');
            dfs(l - 1, r, move(path), sol);
            path.pop_back();
        }
        if (l < r) {
            path.push_back(')');
            dfs(l, r - 1, move(path), sol);
            path.pop_back();
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> sol;
        dfs(n, n, {}, sol);
        return sol;
    }
};

int main(){
    int n;
    cin >> n;
    vector<string> sol = Solution().generateParenthesis(n);
    for (int i = 0; i < sol.size(); i++) {
        cout << sol[i] << endl;
    }
    return 0;
}