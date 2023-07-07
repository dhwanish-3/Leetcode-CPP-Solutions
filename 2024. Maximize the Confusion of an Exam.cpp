#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int len=answerKey.length();
        int sol=0;
        vector<int> count(2,0);
        int maxCount=0;
        for(int l=0,r=0;r<len;r++){
            maxCount=max(maxCount,++count[answerKey[r]=='T']);
            while(maxCount+k<r-l+1){
                --count[answerKey[l]=='T'];
                l++;
            }
            sol=max(sol,r-l+1);
        }
        return sol;
    }
};

int main(){
    int k;
    string s;
    cin>>s;
    cin>>k;
    cout<<Solution().maxConsecutiveAnswers(s,k);
    return 0;
}