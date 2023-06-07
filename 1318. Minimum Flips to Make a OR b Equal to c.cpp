#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void binary(int a){
        stack<int> stk;
        for(int i=0;(1<<i)<=a;i++){
            stk.push(a&(1<<i)?1:0);
        }
        while(!stk.empty()){
            cout<<stk.top();
            stk.pop();
        }
        cout<<endl;
    }
    int minFlips(int a, int b, int c) {
        int flips=0;
        int bit,abit,bbit,cbit;
        for(int i=0;(1<<i)<=max(a,max(b,c));i++){
            bit=1<<i;
            abit=a&bit;
            bbit=b&bit;
            cbit=c&bit;
            if(cbit && !(abit|bbit)) flips++;
            else if(!cbit && (abit&bbit)) flips+=2;
            else if(!cbit && (abit^bbit)) flips++;
        }
        return flips;
    }
};

int main(){
    int a,b,c;
    cin>>a;
    Solution().binary(a);
    cin>>a>>b>>c;
    cout<<Solution().minFlips(a,b,c);    
    return 0;
}