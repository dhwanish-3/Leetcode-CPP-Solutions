#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> hash;
        for (int i = 0; i < n; i++) {
            hash[nums[i]]++;
        }
        int sol = 0;
        for (auto it : hash) {
            if (it.second == 1) {
                return -1;
            } else if (it.second % 3 == 0) {
                sol += (it.second / 3);
            } else {
                sol += ((it.second / 3) + 1);
            }
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
    return 0;
}