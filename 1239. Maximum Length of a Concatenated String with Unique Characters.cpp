#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxLength(vector<string>& arr, string str = "", int index = 0) {
        int n = arr.size();
        unordered_set<char> s(str.begin(), str.end());
        if (s.size() != str.length()) {
            return 0;
        }
        int sol = str.length();
        for (int i = index; i < arr.size(); i++) {
            sol = max(sol, maxLength(arr, str + arr[i], i + 1));
        }
        return sol;
    }
};

int main() {
    int n;
    cin >> n;
    vector<string> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << Solution().maxLength(arr);
    return 0;
}