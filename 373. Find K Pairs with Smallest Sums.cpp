#include <bits/stdc++.h>
using namespace std;
#define pp pair<int, pair<int, int>>

class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int> &nums1, vector<int> &nums2, int k) {
        int n1 = nums1.size(), n2 = nums2.size();
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        for (int i = 0; i < min(k, n1); i++) {
            pq.push({nums1[i] + nums2[0], {i, 0}});
        }
        vector<vector<int>> sol;
        while (k > 0 && !pq.empty()) {
            pair<int, pair<int, int>> top = pq.top();
            pq.pop();
            int i1 = top.second.first;
            int i2 = top.second.second;
            sol.push_back({nums1[i1], nums2[i2]});
            if (i2 + 1 < n2) {
                pq.push({nums1[i1] + nums2[i2 + 1], {i1, i2 + 1}});
            }
            k--;
        }
        return sol;
    }
};

int main() {
    int n1, n2, k;
    cin >> n1;
    vector<int> v1(n1);
    for (int i = 0; i < n1; i++)
        cin >> v1[i];
    cin >> n2;
    vector<int> v2(n2);
    for (int i = 0; i < n2; i++)
        cin >> v2[i];
    cin >> k;
    vector<vector<int>> sol = Solution().kSmallestPairs(v1, v2, k);
    for (int i = 0; i < sol.size(); i++)
    {
        for (int j = 0; j < sol[i].size(); j++)
            cout << sol[i][j] << " ";
        cout << endl;
    }
    return 0;
}