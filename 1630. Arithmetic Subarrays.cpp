#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        int m = l.size();
        vector<bool> sol(m);
        for (int i = 0; i < m; i++) {
            vector<int> sub(nums.begin() + l[i], nums.begin() + r[i] + 1);
            sort(sub.begin(), sub.end());
            int d = sub[1] - sub[0];
            bool ok = true;
            for (int j = 2; j < sub.size(); j++) {
                if (sub[j] - sub[j - 1] != d) {
                    ok = false;
                    break;
                }
            }
            sol[i] = ok;
        }
        return sol;
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    int m;
    cin >> m;
    vector<int> l(m);
    vector<int> r(m);
    for (int i = 0; i < m; i++) {
        cin >> l[i] >> r[i];
    }
    vector<bool> sol = Solution().checkArithmeticSubarrays(nums, l, r);
    for (int i = 0; i < m; i++) {
        cout << (sol[i] ? "true" : "false") << endl;
    }
    return 0;
}