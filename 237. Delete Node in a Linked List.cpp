#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    void deleteNode(ListNode* node) {
        node->val = node->next->val;
        node->next = node->next->next;
    }
};

int main() {
    int n, x;
    cin >> n >> x;
    ListNode* head = new ListNode(x);
    ListNode* cur = head;
    for (int i = 1; i < n; i++) {
        cin >> x;
        cur->next = new ListNode(x);
        cur = cur->next;
    }
    int k;
    cin >> k;
    cur = head;
    while (cur->val != k) {
        cur = cur->next;
    }
    Solution().deleteNode(cur);
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    return 0;
}