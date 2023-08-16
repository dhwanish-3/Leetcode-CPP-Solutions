#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// Apprach 1: Using Extra Space
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        vector<ListNode*> rest;
        ListNode* cur = head;
        ListNode* dummy = new ListNode(3);
        ListNode* sol = dummy;
        while (cur) {
            if (cur->val < x) {
                sol->next = cur;
                sol = cur;
            } else {
                rest.push_back(cur);
            }
            cur = cur->next;
        }
        for (int i=0; i<rest.size(); i++) {
            sol->next = rest[i];
            sol = rest[i];
        }
        sol->next = nullptr;
        ListNode* ans = dummy->next;
        delete dummy;
        return ans;
    }
};

// Approach 2: Without Using Extra Space
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        ListNode* cur = nullptr;
        ListNode* curHead = nullptr;
        ListNode* greater = nullptr;
        ListNode* greatHead = nullptr;
        ListNode* next = nullptr;
        while (head) {
            next = head->next;
            if (head->val >= x) {
                if (greatHead) {
                    greater->next = head;
                    greater = head;
                } else {
                    greatHead = head;
                    greater = head;
                    greatHead->next = nullptr;
                }
            } else {
                if (curHead) {
                    cur->next = head;
                    cur = head;
                } else {
                    curHead = head;
                    cur = head;
                    curHead->next = nullptr;
                }
            }
            head = next;
        }
        if (cur) {
            cur->next = greatHead;
        } else {
            curHead = greatHead;
        }
        if (greater) {
            greater->next = nullptr;
        }
        return curHead;
    }
};

int main(){
    ListNode* h = new ListNode(1);
    h->next = new ListNode(4);
    h->next->next = new ListNode(3);
    h->next->next->next = new ListNode(2);
    h->next->next->next->next = new ListNode(5);
    h->next->next->next->next->next = new ListNode(2);
    int n;
    cin>>n;
    ListNode* sol = Solution().partition(h, n);
    while(sol){
        cout<<sol->val<<"->";
        sol = sol->next;
    }
    return 0;
}