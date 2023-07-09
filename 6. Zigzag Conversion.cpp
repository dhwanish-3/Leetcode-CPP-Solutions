#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        int len = s.length();
        vector<vector<char>> rows(numRows);
        int k = 0;
        int direction = (numRows == 1) - 1;
        for(char c : s) {
            rows[k].push_back(c);
            if(k==0 || k==numRows-1) {
                direction *= -1;
            }
            k += direction;
        }
        string sol;
        for(auto row : rows) {
            for(char c : row) {
                sol += c;
            }
        }
        return sol;
    }
};

int main(){
    int n;
    string s;
    cin>>s>>n;
    cout<<Solution().convert(s,n);
    return 0;
}