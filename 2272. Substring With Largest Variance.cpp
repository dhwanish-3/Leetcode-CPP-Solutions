#include <bits/stdc++.h>
using namespace std;

class Solution {
    int kadane(const string& s, char a, char b) {
        int sol = 0;
        int countA = 0, countB = 0;
        bool canExtendPrevB = false;
        for(const char c : s) {
            if(c != a && c != b) continue;
            if(c == a) countA++;
            if(c == b) countB++;
            if(countB > 0) {
                sol = max(sol, countA-countB);
            } else if(countB == 0 && canExtendPrevB){
                sol = max(sol, countA-1);
            }
            if(countB > countA) {
                countA = 0;
                countB = 0;
                canExtendPrevB = true;
            }
        }
        return sol;
    }
public:
    int largestVariance(string s) {
        int sol = 0;
        for(char i='a' ; i<='z' ; i++){
            for(char j='a' ; j<='z' ; j++){
                if(i != j){
                    sol = max(sol, kadane(s, i ,j));
                }
            }
        }
        return sol;
    }
};

int main(){
    string s;
    cin>>s;
    cout<<Solution().largestVariance(s);
    return 0;
}