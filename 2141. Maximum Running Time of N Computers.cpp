#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maxRunTime(int n, vector<int>& batteries) {
        long long sum = 0;
        int size = batteries.size();
        for (int i = 0; i < size; i++) {
            sum += batteries[i];
        }
        sort(batteries.begin(), batteries.end());
        while (batteries.back() > sum / n) {
            sum -= batteries.back();
            batteries.pop_back();
            n--;
        }
        return sum / n;
    }
};

int main(){
    int n, k;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    cin >> k;
    cout << Solution().maxRunTime(k, v);
    return 0;
}