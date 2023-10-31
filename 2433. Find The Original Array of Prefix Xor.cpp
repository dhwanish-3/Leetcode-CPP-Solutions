#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        int n = pref.size();
        vector<int> sol(n);
        sol[0] = pref[0];
        for (int i = 1; i < n; i++) {
            sol[i] = pref[i] ^ pref[i - 1];
        }
        return sol;
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> pref(n);
    for (int i = 0; i < n; i++) {
        cin >> pref[i];
    }
    vector<int> ans = Solution().findArray(pref);
    for (int i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }
    return 0;
}