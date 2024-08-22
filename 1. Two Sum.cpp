#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int, int> hash;
        for (int i = 0; i < n; i++) {
            hash[nums[i]] = i;
        }
        for (int i = 0; i < n; i++) {
            auto it = hash.find(target - nums[i]);
            if (it != hash.end()) {
                if (it->second != i) return {i, it->second};
            }
        }
        return {};
    }
};

int main() {
    int n, in, tar;
    vector<int> nums;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> in;
        nums.push_back(in);
    }
    cin >> tar;
    vector<int> sol = Solution().twoSum(nums,tar);
    cout << sol[0] << " " << sol[1] << endl;
    return 0;
}