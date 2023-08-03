#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        while (n) {
            n &= (n - 1);
            count++;
        }
        return count;
    }
};

int main(){
    uint32_t n;
    cin>>n;
    cout << Solution().hammingWeight(n);
    return 0;
}