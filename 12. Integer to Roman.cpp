#include <bits/stdc++.h>
using namespace std;

class Solution {
    const vector<string> M{"","M","MM","MMM"};
    const vector<string> C{"","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"};
    const vector<string> X{"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"};
    const vector<string> I{"","I","II","III","IV","V","VI","VII","VIII","IX"};
public:
    string intToRoman(int num) {
        return M[(num/1000)%4]+C[(num/100)%10]+X[(num/10)%10]+I[num%10];
    }
};

int main(){
    int n;
    cin>>n;
    cout<<Solution().intToRoman(n);
    
    return 0;
}