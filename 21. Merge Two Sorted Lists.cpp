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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* dummy=new ListNode(0);
        ListNode* cur=dummy;
        while(list1 || list2){
            if(list1 && list2){
                if((list1->val)<(list2->val)){
                    ListNode* node=new ListNode(list1->val);
                    cur->next=node;
                    cur=node;
                    list1=list1->next;
                }else{
                    ListNode* node=new ListNode(list2->val);
                    cur->next=node;
                    cur=node;
                    list2=list2->next;
                }
            }
            else if(list1){
                ListNode* node=new ListNode(list1->val);
                cur->next=node;
                cur=node;
                list1=list1->next;
            }
            else if(list2){
                ListNode* node=new ListNode(list2->val);
                cur->next=node;
                cur=node;
                list2=list2->next;
            }
        }
        ListNode* head=dummy->next;
        delete dummy;
        return head;
    }
};

int main(){
    int n1,n2,in;
    cin>>n1>>n2;
    ListNode* dummy1=new ListNode(0);
    ListNode* cur=dummy1;
    for(int i=0;i<n1;i++){
        cin>>in;
        ListNode* node=new ListNode(in);
        cur->next=node;
        cur=node;
    }
    ListNode* dummy2=new ListNode(0);
    cur=dummy2;
    for(int i=0;i<n2;i++){
        cin>>in;
        ListNode* node=new ListNode(in);
        cur->next=node;
        cur=node;
    }
    ListNode* res=Solution().mergeTwoLists(dummy1->next,dummy2->next);
    cur=res;
    while(cur){
        cout<<cur->val<<" ";
        cur=cur->next;
    }
    return 0;
}