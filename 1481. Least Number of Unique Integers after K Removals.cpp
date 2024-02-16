#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        int n = arr.size();
        unordered_map<int, int> hash;
        for (int i = 0; i < n; i++) {
            hash[arr[i]]++;
        }
        vector<pair<int, int>> map;
        for (auto it : hash) {
            map.push_back(make_pair(it.second, it.first));
        }
        sort(map.begin(), map.end());
        int sol = map.size();
        for (int i = 0; i < map.size(); i++) {
            if (map[i].first <= k) {
                k -= map[i].first;
                sol--;
            } else {
                break;
            }
        }
        return sol;
    }
};

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << Solution().findLeastNumOfUniqueInts(arr, k);
    return 0;
}