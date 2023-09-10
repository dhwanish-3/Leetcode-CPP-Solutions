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
    void reorderList(ListNode* head) {
        if (!head || !head->next || !head->next->next) {
            return;
        }
        stack<ListNode*> s;
        ListNode* cur = head;
        while (cur) {
            s.push(cur);
            cur = cur->next;
        }
        int size = s.size();
        cur = head;
        ListNode* last = nullptr;
        for (int i = 0; i < size / 2; i++) {
            last = s.top();
            s.pop();
            last->next = cur->next;
            cur->next = last;
            cur = last->next;
        }
        cur->next = nullptr;
    }
};

int main() {
    ListNode* head = new ListNode(1);
    ListNode* cur = head;
    for (int i = 2; i <= 4; i++) {
        cur->next = new ListNode(i);
        cur = cur->next;
    }
    Solution().reorderList(head);
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    return 0;
}