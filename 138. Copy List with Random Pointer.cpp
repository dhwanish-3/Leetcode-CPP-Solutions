#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
    Node* find(Node* head, int val) {
        while(head){
            if(head->val == val) {
                return head;
            }
            head = head->next;
        }
        return nullptr;
    }
public:
    Node* copyRandomList(Node* head) {
        Node* dummy = new Node(0);
        Node* cur = dummy;
        Node* temp = head;
        unordered_map<Node*, Node*> hash;
        while(temp) {
            Node* node = new Node(temp->val);
            hash[temp] = node;
            cur->next = node;
            cur = node;
            temp = temp->next;
        }
        cur = dummy->next;
        temp = head;
        while(temp) {
            Node* search = nullptr;
            if(temp->random) {
                auto it = hash.find(temp->random);
                if(it != hash.cend()) search = it->second;
            }
            cur->random = search;
            cur = cur->next;
            temp = temp->next;
        }
        Node* copy = dummy->next;
        delete dummy;
        return copy;
    }
};

int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    
    return 0;
}