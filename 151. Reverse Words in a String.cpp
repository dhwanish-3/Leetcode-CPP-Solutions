#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        int len=s.length();
        int start=0;
        int end=0;
        stack<string> strs;
        for(int i=1;i<len;i++){
            if(s[i]==' '){
                // cout<<"->"<<s[start]<<"<-"<<endl;
                while(s[start]==' '){
                    cout<<start<<endl;
                    start++;
                }
                end=i;
                if(s[i-1]!=' ' && end-start!=0){
                    strs.push(s.substr(start,end-start));
                }
                start=i+1;
            }
        }
        if(s[len-2]!=' '){
            while(s[start]==' '){
                start++;
            }
            end=len-1;
            while(s[end+1]==' '){
                end--;
            }
            if(end-start!=0)
                strs.push(s.substr(start,end-start));
        }
        s="";
        while(!strs.empty()){
            if(strs.top().length()!=0){
                s.append(strs.top());
                cout<<"->"<<strs.top()<<"<-"<<endl;
                strs.pop();
                if(!strs.empty()) s.append(" ");
            }else strs.pop();
        }
        return s;
    }
};

int main(){
    string s;
    getline(cin,s);
    cout<<"string ->"<<Solution().reverseWords(s)<<"<-";
    return 0;
}