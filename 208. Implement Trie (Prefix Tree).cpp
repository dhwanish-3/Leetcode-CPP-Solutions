#include <bits/stdc++.h>
using namespace std;

class TrieNode {
public:
    vector<TrieNode*> data;
    bool isEndOfWord;
    TrieNode() {
        data.resize(26);
        isEndOfWord = false;
    }
};

class Trie {
    TrieNode* root;
    TrieNode* find(string& prefix) {
        TrieNode* cur = root;
        for (int i = 0; i < prefix.length(); i++) {
            int ch = prefix[i] - 'a';
            if (cur->data[ch] == nullptr) {
                return nullptr;
            }
            cur = cur->data[ch];
        }
        return cur;
    }
public:
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        int len = word.length();
        TrieNode* cur = root;
        for (int i = 0; i < len; i++) {
            int ch = word[i] - 'a';
            if (!cur->data[ch]) {
                cur->data[ch] = new TrieNode();
            }
            cur = cur->data[ch];
        }
        cur->isEndOfWord = true;
    }
    
    bool search(string word) {
        TrieNode* res = find(word);
        return res && res->isEndOfWord;
    }
    
    bool startsWith(string prefix) {
        return find(prefix) != nullptr;
    }
};

int main() {
    Trie* obj = new Trie();
    obj->insert("word");
    cout << obj->search("word");
    cout << obj->startsWith("prefix");
    return 0;
}