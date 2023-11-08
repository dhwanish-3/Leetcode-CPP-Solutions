#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        vector<double> time(dist.size());
        for (int i = 0; i < dist.size(); i++) {
            time[i] = (double)dist[i] / speed[i];
        }
        sort(time.begin(), time.end());
        int ans = 0;
        for (int i = 0; i < time.size(); i++) {
            if (time[i] <= i) {
                break;
            }
            ans++;
        }
        return ans;
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> dist(n), speed(n);
    for (int i = 0; i < n; i++) {
        cin >> dist[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> speed[i];
    }
    cout << Solution().eliminateMaximum(dist, speed) << endl;
    return 0;
}