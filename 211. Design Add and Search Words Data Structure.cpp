#include <bits/stdc++.h>
using namespace std;

struct TrieNode {
    vector<shared_ptr<TrieNode>> children;
    bool isWord = false;
    TrieNode() : children(26) {}
};

class WordDictionary {
    shared_ptr<TrieNode> root = make_shared<TrieNode> ();
    bool dfs(string& word, int s, shared_ptr<TrieNode> node) {
        if (s == word.length()) {
            return node->isWord;
        }
        if (word[s] != '.') {
            shared_ptr<TrieNode> next = node->children[word[s] - 'a'];
            return next ? dfs(word, s+1, next) : false;
        }
        // word[s] = '.' -> search all 26 children
        for (int i=0 ; i<26 ; i++) {
            if (node->children[i] && dfs(word, s+1, node->children[i])) {
                return true;
            }
        }
        return false;
    }
public:
    WordDictionary() {
        
    }
    
    void addWord(string word) {
        shared_ptr<TrieNode> node = root;
        for (char c: word) {
            int i = c -'a';
            if (node->children[i] == nullptr) {
                node->children[i] = make_shared<TrieNode> ();
            }
            node = node->children[i];
        }
        node->isWord = true;
    }
    
    bool search(string word) {
        return dfs(word, 0 ,root);   
    }
};

int main(){
    WordDictionary* obj = new WordDictionary();
    obj->addWord("word");
    cout<<obj->search("word");
    
    return 0;
}