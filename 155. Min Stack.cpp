#include <bits/stdc++.h>
using namespace std;

class MinStack {
    stack<pair<int,int>> stk;
public:
    MinStack(){}

    void push(int val) {
        if(stk.empty()){
            stk.emplace((val, val));
        }else
            stk.emplace((val, min(val, stk.top().second)));
    }

    void pop() {
        stk.pop();
    }

    int top() {
        return stk.top().first;
    }

    int getMin() {
        return stk.top().second;
    }
};

int main(){
    int a;
    char ch;
    MinStack* stk = new MinStack();
    while(3){
        cin>>ch;
        cout<<ch;
        switch(ch){
            case 'i':
                cin>>a;
                cout<<a;
                stk->push(a);
                break;
            case 'p':
                stk->pop();
                break;
            case 't':
                cout<<stk->top()<<endl;
                break;
            case 'm':
                cout<<stk->getMin()<<endl;
                break;
        }
    }
    return 0;
}