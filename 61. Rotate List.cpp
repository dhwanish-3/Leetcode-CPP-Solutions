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
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr || head->next == nullptr) return head;
        ListNode* cur = head;
        ListNode* prev = nullptr;
        int i = 0;
        int size = 0;
        while (cur) {
            prev = cur;
            cur = cur->next;
            i++;
        }
        size = i;
        prev->next = head;
        cur = head;
        k = k % size;
        k++;
        i = 0;
        while (i < size-k && cur) {
            prev = cur;
            cur = cur->next;
            i++;
        }
        head = cur;
        prev->next = nullptr;
        return head;
    }
};

int main(){
    
    
    return 0;
}