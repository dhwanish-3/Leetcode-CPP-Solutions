#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> engaged;
        priority_queue<int, vector<int>, greater<int>> available;
        unordered_map<int, int> freq;
        for (int i = 0; i < n; i++) {
            available.push(i);
        }
        for (int i = 0; i < meetings.size(); i++) {
            while (!engaged.empty() && engaged.top().first <= meetings[i][0]) {
                available.push(engaged.top().second);
                engaged.pop();
            }
            if (available.size() > 0) {
                int room = available.top();
                available.pop();
                freq[abs(room)]++;
                engaged.push({meetings[i][1], room});
            } else {
                pair<long long, int> top = engaged.top();
                engaged.pop();
                freq[abs(top.second)]++;
                long long newEnd = top.first;
                newEnd += meetings[i][1] - meetings[i][0];
                engaged.push({newEnd, top.second});
            }
        }
        int maxFreq = 0;
        for (int i = 1; i < n; i++) {
            if (freq[i] > freq[maxFreq]) {
                maxFreq = i;
            }
        }
        return maxFreq;
    }
};

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> v(m, vector<int>(2));
    for (int i = 0; i < m; i++) cin >> v[i][0] >> v[i][1];
    cout << Solution().mostBooked(n, v);
    return 0;
}