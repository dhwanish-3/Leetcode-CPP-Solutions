#include <bits/stdc++.h>
using namespace std;

class Solution {
    static bool compare(vector<int> a, vector<int> b) {
        return a[1] < b[1];
    }
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        int n = flowers.size();
        int start[n];
        int end[n];
        sort(flowers.begin(), flowers.end());
        for (int i = 0; i < n; i++) {
            start[i] = flowers[i][0];
        }
        sort(flowers.begin(), flowers.end(), compare);
        for (int i = 0; i < n; i++) {
            end[i] = flowers[i][1];
        }
        vector<int> sol;
        for (int i = 0; i < people.size(); i++) {
            int bloom = upper_bound(start, start + n, people[i]) - start;
            int notBloom = lower_bound(end, end + n, people[i]) - end;
            sol.push_back(bloom - notBloom);
        }
        return sol;
    }
};

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> flowers(n, vector<int>(2));
    for (int i = 0; i < n; i++) {
        cin >> flowers[i][0] >> flowers[i][1];
    }
    vector<int> people(m);
    for (int i = 0; i < m; i++) {
        cin >> people[i];
    }
    vector<int> sol = Solution().fullBloomFlowers(flowers, people);
    for (int& s : sol) {
        cout << s << " ";
    }
    return 0;
}