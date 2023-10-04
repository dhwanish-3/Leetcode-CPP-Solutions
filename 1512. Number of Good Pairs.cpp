#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int hash[101] = {0};
        int count = 0;
        for (int i = 0; i < nums.size(); i++) {
            count += hash[nums[i]]++;
        }
        return count;
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    cout << Solution().numIdenticalPairs(nums) << endl;
    return 0;
}