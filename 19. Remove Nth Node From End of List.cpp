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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head->next == nullptr) return nullptr;
        ListNode* cur = head;
        ListNode* nLeap = head;
        while (n--) {
            nLeap = nLeap->next;
        }
        if (nLeap == nullptr) return head->next;
        while (nLeap->next) {
            cur = cur->next;
            nLeap = nLeap->next;
        }
        if (cur && cur->next) {
            cur->next = cur->next->next;
        }
        return head;
    }
};

int main(){
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    head = Solution().removeNthFromEnd(head,4);
    while(head){
        cout<<head->val<<"->";
        head = head->next;
    }
    return 0;
}