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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> sol(k);
        if (head == nullptr) {
            return sol;
        }
        ListNode* cur = head;
        int len = 1;
        while (cur->next) {
            len++;
            cur = cur->next;
        }
        int i = 0, j = 0;
        cur = head;
        ListNode* next = head;
        while (i < len % k) {
            ListNode* h = next;
            cur = next;
            j = 0;
            while (j < (len / k)) {
                cur = cur->next;
                j++;
            }
            next = cur->next;
            cur->next = nullptr;
            sol[i] = h;
            i++;
        }
        while (i < k) {
            ListNode* h = next;
            cur = next;
            j = 0;
            while (j < (len / k) - 1) {
                cur = cur->next;
                j++;
            }
            if (cur) {
                cout << cur->val << endl;
                next = cur->next;
                cur->next = nullptr;
            }
            sol[i] = h;
            i++;
        }
        return sol;
    }
};

int main() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    vector<ListNode*> sol = Solution().splitListToParts(head, 3);
    for (int i = 0; i < sol.size(); i++) {
        ListNode* cur = sol[i];
        while (cur) {
            cout << cur->val << " ";
            cur = cur->next;
        }
        cout << endl;
    }
    return 0;
}