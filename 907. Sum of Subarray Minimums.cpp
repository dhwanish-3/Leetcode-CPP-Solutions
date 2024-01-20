#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int mod = 1e9 + 7;
        int n = arr.size();
        vector<int> left(n), right(n);
        stack<int> s;
        for (int i = 0; i < n; i++) {
            while (!s.empty() && arr[s.top()] > arr[i]) {
                s.pop();
            }
            if (s.empty()) {
                left[i] = -1;
            } else {
                left[i] = s.top();
            }
            s.push(i);
        }
        while (!s.empty()) {
            s.pop();
        }
        for (int i = n - 1; i >= 0; i--) {
            while (!s.empty() && arr[s.top()] >= arr[i]) {
                s.pop();
            }
            if (s.empty()) {
                right[i] = n;
            } else {
                right[i] = s.top();
            }
            s.push(i);
        }
        int sol = 0;
        for (int i = 0; i < n; i++) {
            long prod = (long)((i - left[i]) * (right[i] - i)) % mod;
            prod = (long)prod * arr[i] % mod;
            sol = (int)(sol + prod) % mod;
        }
        return sol % mod;
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << Solution().sumSubarrayMins(arr);
    return 0;
}