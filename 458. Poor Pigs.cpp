#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        return ceil(log2(buckets) / log2(int(minutesToTest / minutesToDie) + 1));
    }
};

int main() {
    int buckets, minutesToDie, minutesToTest;
    cin >> buckets >> minutesToDie >> minutesToTest;
    cout << Solution().poorPigs(buckets, minutesToDie, minutesToTest) << endl;
    return 0;
}