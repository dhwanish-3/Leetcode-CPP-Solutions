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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dummy = new ListNode(3);
        ListNode* cur = dummy;
        while (head) {
            if (head->next && head->val != head->next->val) {
                cur->next = head;
                cur = head;
            } else if (!head->next) {
                cur->next = head;
                cur = head;
            }
            head = head->next;
        }
        cur->next = nullptr;
        ListNode* sol = dummy->next;
        delete dummy;
        return sol;
    }
};

int main(){
    ListNode* head = new ListNode(1);
    ListNode* node1 = new ListNode(1);
    ListNode* node2 = new ListNode(2);
    head->next = node1;
    node1->next = node2;
    ListNode* sol = Solution().deleteDuplicates(head);
    while (sol != nullptr) {
        cout << sol->val << " ";
        sol = sol->next;
    }
    cout << endl;
    return 0;
}