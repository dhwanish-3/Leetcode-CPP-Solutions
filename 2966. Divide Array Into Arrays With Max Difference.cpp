#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> sol(n / 3, vector<int>(3));
        int groupIndex = 0;
        for (int i = 0; i < n; i += 3) {
            if (i + 2 < n && nums[i + 2] - nums[i] <= k) {
                sol[groupIndex] = { nums[i], nums[i + 1], nums[i + 2] };
                groupIndex++;
            } else {
                return {};
            }
        }
        return sol;
    }
};

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    vector<vector<int>> sol = Solution().divideArray(v, k);
    for (auto& v : sol) {
        for (auto& i : v) {
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}