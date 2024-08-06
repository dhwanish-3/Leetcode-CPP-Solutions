#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNodes(ListNode* head) {
        ListNode* cur = head;
        ListNode* prev = nullptr;
        ListNode* next = head;
        while (cur) {
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        head = prev;
        cur = head;
        int curMax = cur->val;
        cur = cur->next;
        head->next = nullptr;
        while (cur) {
            cout << cur->val << " ";
            next = cur->next;
            if (cur->val >= curMax) {
                cur->next = head;
                head = cur;
                cout << curMax << " max\n";
                curMax = cur->val;
            }
            cur = next;
        }
        return head;
    }
};

int main() {
    
    return 0;
}