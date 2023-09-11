#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        unordered_map<int, vector<int>> hash;
        for (int i = 0; i < groupSizes.size(); i++) {
            hash[groupSizes[i]].push_back(i);
        }
        vector<vector<int>> sol;
        for (auto it : hash) {
            int size = it.first;
            int i = 0;
            vector<int> v;
            for (int person : it.second) {
                v.push_back(person);
                if (v.size() == size) {
                    sol.push_back(v);
                    v.resize(0);
                }
            }
        }
        return sol;
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> groupSizes(n);
    for (int i = 0; i < n; i++) {
        cin >> groupSizes[i];
    }
    vector<vector<int>> sol = Solution().groupThePeople(groupSizes);
    for (auto v : sol) {
        for (int i : v) {
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}