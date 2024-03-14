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
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode* dummy = new ListNode(3);
        dummy->next = head;
        unordered_map<int, ListNode*> prefixSumToNode;
        int prefixSum = 0;
        for (ListNode* cur = dummy; cur != nullptr; cur = cur->next) {
            prefixSum += cur->val;
            if (prefixSumToNode.count(prefixSum)) {
                ListNode* prev = prefixSumToNode[prefixSum];
                ListNode* toRemove = prev->next;
                int p = prefixSum + (toRemove ? toRemove->val : 0);
                while (p != prefixSum) {
                    prefixSumToNode.erase(p);
                    toRemove = toRemove->next;
                    p += (toRemove ? toRemove->val : 0);
                }
                prev->next = cur->next;
            } else {
                prefixSumToNode[prefixSum] = cur;
            }
        }
        return dummy->next;
    }
};

int main() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(-3);
    head->next->next->next = new ListNode(3);
    head->next->next->next->next = new ListNode(1);
    ListNode* sol = Solution().removeZeroSumSublists(head);
    while (sol != nullptr) {
        cout << sol->val << " ";
        sol = sol->next;
    }
    return 0;
}