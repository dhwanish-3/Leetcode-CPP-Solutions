#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int n = arr.size();
        int sol = arr[0];
        if (k >= n) {
            sol = max(arr[0], arr[1]);
            for (int i = 2; i < n; i++) {
                sol = max(sol, arr[i]);
            }
        } else {
            queue<int> q;
            for (int i = 1; i < n; i++) {
                q.push(arr[i]);
            }
            int count = 0;
            while (count < k) {
                if (sol > q.front()) {
                    count++;
                    int num = q.front();
                    q.pop();
                    q.push(num);
                } else {
                    count = 1;
                    q.push(sol);
                    sol = q.front();
                    q.pop();
                }
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
    cout << Solution().getWinner(arr, k) << endl;
    return 0;
}