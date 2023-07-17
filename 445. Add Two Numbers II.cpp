#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> first;
        stack<int> second;
        while (l1) {
            first.push(l1->val);
            l1 = l1->next;
        }
        while (l2) {
            second.push(l2->val);
            l2 = l2->next;
        }
        int carry = 0;
        ListNode* cur = nullptr;
        while (!first.empty() || !second.empty() || carry) {
            if (!first.empty()) {
                carry += first.top();
                first.pop();
            }
            if (!second.empty()) {
                carry += second.top();
                second.pop();
            }
            ListNode* node = new ListNode(carry % 10);
            node->next = cur;
            cur = node;
            carry /= 10;
        }
        return cur;
    }
};

int main(){
    
    
    return 0;
}