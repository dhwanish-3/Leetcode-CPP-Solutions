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
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        ListNode* prev = nullptr;
        ListNode* cur = head;
        ListNode* next = head;
        while (cur) {
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        return prev;
    }
};

int main() {
    int n;
    cin >> n;
    ListNode* head = nullptr;
    ListNode* cur = nullptr;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (head == nullptr) {
            head = new ListNode(x);
            cur = head;
        } else {
            cur->next = new ListNode(x);
            cur = cur->next;
        }
    }
    ListNode* ans = Solution().reverseList(head);
    while (ans) {
        cout << ans->val << " ";
        ans = ans->next;
    }
    return 0;
}