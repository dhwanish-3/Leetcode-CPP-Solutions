#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int n = dist.size();
        if (n > ceil(hour)) {
            return -1;
        }
        int l = 1, r = 1e9;
        while (l < r) {
            int mid = (l + r) / 2;
            double sum = 0;
            for (int i = 0; i < n - 1; i++) {
                sum += ceil((double)dist[i] / mid);
            }
            sum += (double)dist[n - 1] / mid;
            if (sum <= hour) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }
};

int main(){
    int n;
    double hour;
    cin >> n >> hour;
    vector<int> dist(n);
    for (int i = 0; i < n; i++) {
        cin >> dist[i];
    }
    cout << Solution().minSpeedOnTime(dist, hour);
    return 0;
}