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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left==right) return head;
        ListNode tempHead(0,head);
        ListNode* prev=&tempHead;
        int i=0;
        while(i<left-1){
            prev=prev->next;
            i++;
        }
        ListNode* tail=prev->next;
        i=0;
        while(i<right-left){
            ListNode* mid=tail->next;
            cout<<mid->val<<endl;
            tail->next=mid->next;
            mid->next=prev->next;
            prev->next=mid;
            i++;
        }
        return tempHead.next;
    }
};

int main(){
    int n,in,l,r;
    cin>>n;
    vector<int> v;
    ListNode* head=nullptr;
    for(int i=0;i<n;i++){
        cin>>in;
        v.push_back(in);
    }
    cin>>l>>r;
    ListNode* currNode=nullptr;
    for(int i=0;i<n;i++){
        ListNode* newNode=new ListNode(v[i]);
        if(head==nullptr) head=newNode;
        else currNode->next= newNode;
        currNode=newNode;
    }
    ListNode* res=Solution().reverseBetween(head,l,r);
    ListNode* temp=res;
    while(temp){
        cout<<temp->val<<"->";
        temp=temp->next;
    }
    return 0;
}