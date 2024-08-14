#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int reverse(long x) {
        long num = 0;
        bool flag = false;
        if (x < 0) {
            flag = true;
            x = -x;
        }
        while (x > 0) {
            num = num * 10 + abs(x % 10);
            if (num > INT_MAX) {
                return 0;
            }
            x /= 10;
        }
        return flag ? -num : num;
    }
};