#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string largestGoodInteger(string num) {
        int n = num.size();
        char sol = 0;
        for (int i = 2; i < n; i++) {
            if (num[i] == num[i - 1] && num[i - 1] == num[i - 2]) {
                sol = max(sol, num[i]);
            }
        }
        return sol == 0 ? "" : string(3, sol);
    }
};

int main() {
    string num;
    cin >> num;
    cout << Solution().largestGoodInteger(num);
    return 0;
}