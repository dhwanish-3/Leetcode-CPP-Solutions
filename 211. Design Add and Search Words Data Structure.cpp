#include <bits/stdc++.h>
using namespace std;

class TrieNode {
public:
    vector<TrieNode*> data;
    bool isEndOfWord = false;
    TrieNode() {
        data.resize(26);
    }
};

class WordDictionary {
    TrieNode* root;
public:
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* cur = root;
        for (int i = 0; i < word.length(); i++) {
            int j = word[i] - 'a';
            if (!cur->data[j]) {
                cur->data[j] = new TrieNode();
            }
            cur = cur->data[j];
        }
        cur->isEndOfWord = true;
    }

    bool rec(string word, TrieNode* cur, int i) {
        if (word.length() == i) {
            return cur->isEndOfWord;
        }
        if (word[i] == '.') {
            for (int j = 0; j < 26; j++) {
                if (cur->data[j]) {
                    if (rec(word, cur->data[j], i + 1)) {
                        return true;
                    }
                }
            }
            return false;
        } else {
            int ch = word[i] - 'a';
            if (cur->data[ch] == nullptr) {
                return false;
            }
            return rec(word, cur->data[ch], i + 1);
        }
    }
    
    bool search(string word) {
        return rec(word, root, 0);
    }
};

int main() {
    WordDictionary* obj = new WordDictionary();
    obj->addWord("word");
    cout << obj->search("word");
    return 0;
}