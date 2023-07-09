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
        if(head == nullptr || head->next == nullptr) return head;
        ListNode* dummy = new ListNode(3, head);
        ListNode* cur = head;
        ListNode* lead = dummy;
        while(cur) {
            while(cur->next && cur->val == cur->next->val) {
                cur = cur->next;
            }
            if(lead->next == cur) {
                lead = lead->next;
            } else {
                lead->next = cur->next;
            }
            cur = cur->next;
        }
        ListNode* node = dummy->next;
        delete dummy;
        return node;
    }
};

int main(){
    
    
    return 0;
}