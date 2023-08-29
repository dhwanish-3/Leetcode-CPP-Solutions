#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int bestClosingTime(string cust) {
        int len = cust.length();
        int minPenalty = INT_MAX;
        int earlyClose = 0;
        int yCount = 0;
        int y = 0, n = 0, penalty = 0;
        for (int i = 0; i < len; i++) {
            if (cust[i] == 'Y') {
                yCount++;
            }
        }
        if (yCount == len) {
            return len;
        } else if (yCount == 0) {
            return 0;
        }
        for (int i = 0; i < len; i++) {
            penalty = yCount - y + n;
            cout << penalty << endl;
            if (cust[i] == 'Y') {
                y++;
            } else {
                n++;
            }
            if (penalty < minPenalty) {
                minPenalty = penalty;
                earlyClose = i;
            }
        }
        if (yCount - y + n < minPenalty) {
            earlyClose = len;
        } 
        return earlyClose;
    }
};

int main() {
    string cust;
    cin >> cust;
    cout << Solution().bestClosingTime(cust) << endl;
    return 0;
}