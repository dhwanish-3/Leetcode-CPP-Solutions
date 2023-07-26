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
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }
        ListNode* slow = head;
        ListNode* fast = head->next;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next;
            fast = fast->next;
        }
        ListNode* mid = slow->next;
        slow->next = nullptr;
        ListNode* left = sortList(head);
        ListNode* right = sortList(mid);
        ListNode* dummy = new ListNode(0);
        ListNode* cur = dummy;
        while (left && right) {
            if (left->val < right->val) {
                cur->next = left;
                left = left->next;
                cur = cur->next;
            } else {
                cur->next = right;
                right = right->next;
                cur = cur->next;
            }
        }
        if (left) {
            cur->next = left;
        }
        if (right) {
            cur->next = right;
        }
        return dummy->next;
    }
};

int main(){
    ListNode* head = new ListNode(4);
    ListNode* node1 = new ListNode(2);
    ListNode* node2 = new ListNode(1);
    ListNode* node3 = new ListNode(3);
    head->next = node1;
    node1->next = node2;
    node2->next = node3;
    ListNode* sol = Solution().sortList(head);
    while (sol != nullptr) {
        cout<<sol->val<<" ";
        sol = sol->next;
    }
    return 0;
}