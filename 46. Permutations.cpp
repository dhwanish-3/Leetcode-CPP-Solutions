#include <bits/stdc++.h>
using namespace std;

class Solution {
    vector<vector<int>> sol;
    void rec(vector<int>& nums, int i) {
        if (i == nums.size()) {
            sol.push_back(nums);
            return;
        }
        for (int j = i; j < nums.size(); j++) {
            swap(nums[i], nums[j]);
            rec(nums, i + 1);
            swap(nums[i], nums[j]);
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        rec(nums, 0);
        return sol;
    }
};

int main(){
    int n;
    cin >> n;
    vector<int> v(n, 0);
    for (int i = 0; i < n ;i++) {
        cin >> v[i];
    }
    vector<vector<int>> sol = Solution().permute(v);
    for (int i = 0; i < sol.size(); i++) {
        for (int j = 0; j < sol[i].size(); j++) {
            cout << sol[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}