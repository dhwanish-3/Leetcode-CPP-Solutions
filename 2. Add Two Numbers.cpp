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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy=new ListNode(0);
        int carry=0;
        ListNode* curr=dummy;
        while(l1 || l2 || carry){
            int sum=carry;
            if(l1){
                sum+=l1->val;
                l1=l1->next;
            }
            if(l2){
                sum+=l2->val;
                l2=l2->next;
            }
            ListNode* newNode=new ListNode(sum%10);
            curr->next=newNode;
            curr=newNode;
            carry=sum/10;
        }
        ListNode* res=dummy->next;
        delete dummy;        
        return res;
    }
};

int main(){
    int n1,n2,in;
    cin>>n1>>n2;
    vector<int> v;
    ListNode* num1=nullptr;
    for(int i=0;i<n1;i++){
        cin>>in;
        v.push_back(in);
    }
    ListNode* currNode=nullptr;
    for(int i=0;i<n1;i++){
        ListNode* newNode=new ListNode(v[i]);
        if(num1==nullptr) num1=newNode;
        else currNode->next= newNode;
        currNode=newNode;
    }
    v.clear();
    ListNode* num2=nullptr;
    for(int i=0;i<n2;i++){
        cin>>in;
        v.push_back(in);
    }
    currNode=nullptr;
    for(int i=0;i<n2;i++){
        ListNode* newNode=new ListNode(v[i]);
        if(num2==nullptr) num2=newNode;
        else currNode->next= newNode;
        currNode=newNode;
    }
    ListNode* sum=Solution().addTwoNumbers(num1,num2);
    currNode=sum;
    while(currNode){
        cout<<currNode->val;
        currNode=currNode->next;
    }
    return 0;
}