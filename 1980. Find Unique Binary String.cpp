#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();
        string sol = "";
        for (int i = 0; i < n; i++) {
            sol += nums[i][i] == '0' ? '1' : '0';
        }
        return sol;
    }
};

int main() {
    int n;
    cin >> n;
    vector<string> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    cout << Solution().findDifferentBinaryString(nums) << endl;
    return 0;
}