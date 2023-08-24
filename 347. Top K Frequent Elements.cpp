#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
        unordered_map<int, int> hash;
        vector<int> sol(k);
        int n = nums.size();
        for (int i = 0; i < nums.size(); i++) {
            hash[nums[i]]++;
        }
        for (auto it : hash) {
            q.emplace(it.second, it.first);
            if (q.size() > k) {
                q.pop();
            }
        }
        int i = 0;
        while (i < k) {
            sol[i] = q.top().second;
            q.pop();
            i++;
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
    int k;
    cin >> k;
    vector<int> sol = Solution().topKFrequent(nums, k);
    for (int i = 0; i < sol.size(); i++) {
        cout << sol[i] << " ";
    }
    cout << endl;
    return 0;
}