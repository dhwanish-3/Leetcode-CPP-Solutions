#include <bits/stdc++.h>
using namespace std;

class Solution {
    void rec(int n, unordered_set<string>& sol, string s, int l, int r) {
        if (l == n && r == n) {
            sol.insert(s);
            return;
        }
        if (l > n || r > n) return;
        rec(n, sol, s + "(", l + 1, r);
        if(l > r) {
            rec(n, sol, s + ")", l, r + 1);
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        unordered_set<string> sol;
        rec(n, sol, "", 0, 0);
        return vector<string>(sol.begin(), sol.end());
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