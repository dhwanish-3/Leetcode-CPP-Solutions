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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        int i = 1;
        ListNode* cur = list1;
        while (i < a) {
            cur = cur->next;
            i++;
        }
        ListNode* remove = cur->next;
        cur->next = list2;
        while (i <= b) {
            remove = remove->next;
            i++;
        }
        while (list2->next != nullptr) {
            list2 = list2->next;
        }
        list2->next = remove;
        return list1;
    }
};
