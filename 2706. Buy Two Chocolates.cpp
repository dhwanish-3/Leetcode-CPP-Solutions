#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int buyChoco(vector<int>& price, int money) {
        int min1 = 0;
        int min2 = 0;
        if (price[0] <= price[1]) {
            min1 = price[0];
            min2 = price[1];
        } else {
            min1 = price[1];
            min2 = price[0];
        }
        for (int i = 2; i < price.size(); i++) {
            if (price[i] < min1) {
                min2 = min1;
                min1 = price[i];
            } else if (price[i] < min2) {
                min2 = price[i];
            }
        }
        if (min1 + min2 <= money) {
            return money - (min1 + min2);
        } else {
            return money;
        }
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> price(n);
    for (int i = 0; i < n; i++) {
        cin >> price[i];
    }
    int money;
    cin >> money;
    cout << Solution().buyChoco(price, money);
    return 0;
}