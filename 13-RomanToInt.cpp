#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int value(char s){
        switch(s){
            case 'I': return 1;
            case 'V': return 5;
            case 'X': return 10;
            case 'L': return 50;
            case 'C': return 100;
            case 'D': return 500;
            case 'M': return 1000;
        }
    }
    int romanToInt(string s) {
        int integer=0;
        integer=value(s[0]);
        for(int i=1;i<s.length();i++){
            if(value(s[i-1])<value(s[i])){
                integer-=value(s[i-1]);
                integer+=(value(s[i])-value(s[i-1]));
            }else{
                integer+=value(s[i]);
            }
        }
        cout<<integer<<endl;
        return integer;
    }
};

int main(){
    string s;
    cin>>s;
    Solution().romanToInt(s);
    return 0;
}