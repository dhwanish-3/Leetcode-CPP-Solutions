#include <bits/stdc++.h>
using namespace std;

// Approach 1: Two Queues
class MyStack {
    queue<int> Q;
public:
    MyStack() {
        
    }
    
    void push(int x) {
        queue<int> q;
        q.push(x);
        while (!Q.empty()) {
            q.push(Q.front());
            Q.pop();
        }
        Q = q;
    }
    
    int pop() {
        int top = Q.front();
        Q.pop();
        return top;
    }
    
    int top() {
        return Q.front();
    }
    
    bool empty() {
        return Q.empty();
    }
};

// Approach 2: One Queue
class MyStack {
    queue<int> Q;
public:
    MyStack() {
        
    }
    
    void push(int x) {
        Q.push(x);
        for (int i = 0; i < Q.size() - 1; i++) {
            Q.push(Q.front());
            Q.pop();
        }
    }
    
    int pop() {
        int top = Q.front();
        Q.pop();
        return top;
    }
    
    int top() {
        return Q.front();
    }
    
    bool empty() {
        return Q.empty();
    }
};

int main() {
    MyStack S;
    S.push(1);
    S.push(2);
    cout << S.top() << endl;
    cout << S.pop() << endl;
    cout << S.empty() << endl;
    return 0;
}