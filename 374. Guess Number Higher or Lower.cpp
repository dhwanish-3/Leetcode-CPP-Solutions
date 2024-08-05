#include <bits/stdc++.h>
using namespace std;

/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int l = 1, r = n;
        while (l <= r) {
            int mid = ((long)l + (long)r) / 2;
            int temp = guess(mid);
            if (temp == 0) {
                return mid;
            } else if (temp == -1) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return n;
    }
};

int main() {
    int n;
    cin >> n;
    cout << Solution().guessNumber(n) << "\n";
    return 0;
}