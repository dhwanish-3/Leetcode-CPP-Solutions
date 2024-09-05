#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hash;
        int n = nums.size();
    
        for (int i = 0; i < n; i++) {
            int first = nums[i];
            int second = target - first;
            if (hash.find(second) != hash.end()) {
                return {i, hash[second]};
            }
            hash[first] = i;
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
