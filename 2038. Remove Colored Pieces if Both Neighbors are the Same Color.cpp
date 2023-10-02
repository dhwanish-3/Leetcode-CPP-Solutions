#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool winnerOfGame(string colors) {
        int a = 0;
        int b = 0;
        for (int i = 1; i < colors.length() - 1; i++) {
            if (colors[i - 1] == colors[i] && colors[i] == colors[i + 1]) {
                if (colors[i] == 'A') {
                    a++;
                } else {
                    b++;
                }
            }
        }
        return a > b;
    }
};

int main() {
    string colors;
    cin >> colors;
    cout << Solution().winnerOfGame(colors) << endl;
    return 0;
}