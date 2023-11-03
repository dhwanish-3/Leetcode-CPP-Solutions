#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> op;
        int targetIndex = 0;
        int curNumber = 1;
        while (targetIndex < target.size()) {
            if (target[targetIndex] == curNumber) {
                op.push_back("Push");
                targetIndex++;
            } else {
                op.push_back("Push");
                op.push_back("Pop");
            }
            curNumber++;
        }
        return op;
    }
};

int main() {
    int n, size;
    cin >> n >> size;
    vector<int> target(size);
    for (int i = 0; i < size; i++) {
        cin >> target[i];
    }
    vector<string> op = Solution().buildArray(target, n);
    for (string s : op) {
        cout << s << endl;
    }
    return 0;
}