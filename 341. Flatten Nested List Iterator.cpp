#include <bits/stdc++.h>
using namespace std;


class NestedInteger {
  public:
    // Return true if this NestedInteger holds a single integer, rather than a nested list.
    bool isInteger() const;
    // Return the single integer that this NestedInteger holds, if it holds a single integer
    // The result is undefined if this NestedInteger holds a nested list
    int getInteger() const;
    // Return the nested list that this NestedInteger holds, if it holds a nested list
    // The result is undefined if this NestedInteger holds a single integer
    const vector<NestedInteger> &getList() const;
};


class NestedIterator {
    stack<int> stk;
    void dfs(vector<NestedInteger> nestedList) {
        for (int i = nestedList.size() - 1; i >= 0; i--) {
            if (nestedList[i].isInteger()) {
                stk.push(nestedList[i].getInteger());
            } else {
                dfs(nestedList[i].getList());
            }
        }
    }
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        dfs(nestedList);
    }
    
    int next() {
        int nextInt = stk.top();
        stk.pop();
        return nextInt;
    }
    
    bool hasNext() {
        return !stk.empty();
    }
};

/**
Your NestedIterator object will be instantiated and called as such:
NestedIterator i(nestedList);
while (i.hasNext()) cout << i.next();
 */

int main() {

    return 0;
}