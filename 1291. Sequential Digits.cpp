#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> sol;
        for (int i = 1; i <= 9; i++) {
            int num = i;
            for (int j = i + 1; j <= 9; j++) {
                num = num * 10 + j;
                if (num >= low && num <= high) {
                    sol.push_back(num);
                }
            }
        }
        sort(sol.begin(), sol.end());
        return sol;
    }
};

int main() {
    int low, high;
    cin >> low >> high;
    vector<int> sol = Solution().sequentialDigits(low, high);
    for (int i = 0; i < sol.size(); i++) {
        cout << sol[i] << " ";
    }
    return 0;
}