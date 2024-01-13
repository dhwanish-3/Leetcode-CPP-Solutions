#include <bits/stdc++.h>
using namespace std;

class Solution {
    bool isVowel(char c) {
        switch(c) {
            case 'a': return true;
            case 'e': return true;
            case 'i': return true;
            case 'o': return true;
            case 'u': return true;
            case 'A': return true;
            case 'E': return true;
            case 'I': return true;
            case 'O': return true;
            case 'U': return true;
            default: return false;
        }
        return false;
    }
public:
    bool halvesAreAlike(string s) {
        int len = s.length();
        if (len % 2 != 0) {
            return false;
        }
        int i = 0;
        int count = 0;
        for (int i = 0; i < len / 2; i++) {
            if (isVowel(s[i])) {
                count++;
            }
        }
        for (int i = len / 2; i < len; i++) {
            if (isVowel(s[i])) {
                count--;
            }
        }
        return count == 0;
    }
};

int main() {
    
    return 0;
}