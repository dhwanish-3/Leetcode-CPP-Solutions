#include <bits/stdc++.h>
using namespace std;

class Solution {
    map<char, vector<char>> map = {
        {'2', {'a', 'b', 'c'}},
        {'3', {'d', 'e', 'f'}},
        {'4', {'g', 'h', 'i'}},
        {'5', {'j', 'k', 'l'}},
        {'6', {'m', 'n', 'o'}},
        {'7', {'p', 'q', 'r', 's'}},
        {'8', {'t', 'u', 'v'}},
        {'9', {'w', 'x', 'y', 'z'}}
    };
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) {
            return {};
        }
        int len = digits.length();
        vector<string> sol{""};
        for (int i = 0; i < len; i++) {
            vector<string> temp;
            for (string& s : sol) {
                for (char c : map[digits[i]]) {
                    temp.push_back(s + c);
                }
            }
            sol = move(temp);
        }
        return sol;
    }
};

int main(){
    string s;
    cin >> s;
    vector<string> sol = Solution().letterCombinations(s);
    for (int  i = 0; i<sol.size() ; i++) {
        cout << sol[i] <<endl;
    }
    return 0;
}