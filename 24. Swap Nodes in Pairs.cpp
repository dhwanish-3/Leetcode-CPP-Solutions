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
    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        ListNode* cur = head->next;
        ListNode* next = nullptr;
        ListNode* prev = nullptr;
        while (head && head->next) {
            next = head->next->next;
            if (prev) {
                prev->next = head->next;
            }
            head->next->next = head;
            head->next = next;
            prev = head;
            head = next;
        }
        return cur;
    }
};

int main() {
    int n;
    cin >> n;
    ListNode* head = nullptr;
    ListNode* cur = nullptr;
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        if (head == nullptr) {
            head = new ListNode(val);
            cur = head;
        } else {
            cur->next = new ListNode(val);
            cur = cur->next;
        }
    }
    ListNode* ans = Solution().swapPairs(head);
    while (ans) {
        cout << ans->val << " ";
        ans = ans->next;
    }
    return 0;
}