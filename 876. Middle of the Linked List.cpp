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
    ListNode* middleNode(ListNode* head) {
        ListNode* slowptr=head;
        ListNode* fastptr=head;
        while(fastptr!=nullptr && fastptr->next!=nullptr){
            slowptr=slowptr->next;
            fastptr=fastptr->next->next;
        }
        return slowptr;
    }
};

int main(){
    int n,in;
    cin>>n;
    vector<int> v;
    ListNode* head=nullptr;
    for(int i=0;i<n;i++){
        cin>>in;
        v.push_back(in);
    }
    ListNode* currNode=nullptr;
    for(int i=0;i<n;i++){
        ListNode* newNode=new ListNode(v[i]);
        if(head==nullptr) head=newNode;
        else currNode->next= newNode;
        currNode=newNode;
    }
    ListNode* res=Solution().middleNode(head);
    ListNode* temp=res;
    while(temp){
        cout<<temp->val<<"->";
        temp=temp->next;
    }
    return 0;
}