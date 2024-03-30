#include <stack>
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
    bool isPalindrome(ListNode* head) {
        ListNode* cur = head;
        ListNode* fast = head;
        while (fast && fast->next) {
            fast = fast->next->next;
            cur = cur->next;
        }
        ListNode* prev = nullptr;
        ListNode* next = nullptr;
        while (cur) {
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        cur = head;
        while (prev) {
            if (cur->val != prev->val) {
                return false;
            }
            cur = cur->next;
            prev = prev->next;
        }
        return true;
    }
};