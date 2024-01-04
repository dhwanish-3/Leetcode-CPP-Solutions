#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int n = bank.size();
        int len = bank[0].length();
        vector<int> count;
        for (int i = 0; i < n; i++) {
            int s = 0;
            for (int j = 0; j < len; j++) {
                if (bank[i][j] == '1') {
                    s++;
                }
            }
            if (s > 0) {
                count.push_back(s);
            }
        }
        int sol = 0;
        for (int i = 1; i < count.size(); i++) {
            sol += (count[i] * count[i - 1]);
        }
        return sol;
    }
};

int main() {
    int n;
    cin >> n;
    vector<string> bank(n);
    for (int i = 0; i < n; i++) {
        cin >> bank[i];
    }
    cout << Solution().numberOfBeams(bank);
    return 0;
}