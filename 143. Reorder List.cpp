#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// Solution 1: O(n) time, O(n) space
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

// Solution 2: O(n) time, O(1) space
class Solution2 {
public:
    void reorderList(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head->next;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* next = nullptr;
        ListNode* prev = nullptr;
        while (slow) {
            next = slow->next;
            slow->next = prev;
            prev = slow;
            slow = next;
        }
        ListNode* cur = head;
        ListNode* next2 = nullptr;
        while (cur && prev) {
            next = cur->next;
            next2 = prev->next;
            cur->next = prev;
            prev->next = next;
            cur = next;
            prev = next2;
        }
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