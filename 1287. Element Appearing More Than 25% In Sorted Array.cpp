#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int n = arr.size();
        int count = 1;
        for (int i = 1; i < n; i++) {
            if (arr[i] == arr[i - 1]) {
                count++;
            } else {
                count = 1;
            }
            if (count > n / 4) {
                return arr[i];
            }
        }
        return arr[0];
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << Solution().findSpecialInteger(arr) << endl;
    return 0;
}