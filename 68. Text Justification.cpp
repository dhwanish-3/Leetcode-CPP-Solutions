#include <bits/stdc++.h>
using namespace std;

class Solution {
    int findRight(int left, vector<string>& words, int maxWidth) {
        int right = left;
        int sum = words[right++].length();
        while (right < words.size() && (sum + 1 + words[right].length() <= maxWidth)) {
            sum += 1 + words[right++].length();
        }
        return right - 1;
    }

    string padResult(string res, int maxWidth) {
        return res + string(maxWidth - res.length(), ' ');
    }

    int wordsLength(int left, int right, vector<string>& words) {
        int wordsLen = 0;
        for (int i = left; i <= right; i++) {
            wordsLen += words[i].size();
        }
        return wordsLen;
    }

    string trim(string s) {
        int left = 0, right = s.length() - 1;
        while (left <= right && isspace(s[left])) {
            left++;
        }
        while (left <= right && isspace(s[right])) {
            right--;
        }
        return s.substr(left, right - left + 1);
    }

    string justify(int left, int right, vector<string>& words, int maxWidth) {
        if (left == right) {
            return padResult(words[left], maxWidth);
        }
        int numSpaces = right - left;
        bool isLast = right == words.size() - 1;
        int totalSpace = maxWidth - wordsLength(left, right, words);
        string space = isLast ? " " : string(totalSpace / numSpaces, ' ');
        int reminder = isLast ? 0 : totalSpace % numSpaces;
        string result = "";
        for (int i = left; i <= right; i++) {
            result += words[i];
            result += space;
            result += (reminder-- > 0 ? " " : "");
        }
        return padResult(trim(result), maxWidth);
    } 
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int left = 0;
        vector<string> sol;
        while (left < words.size()) {
            int right = findRight(left, words, maxWidth);
            sol.push_back(justify(left, right, words, maxWidth));
            left = right + 1;
        }
        return sol;
    }
};

int main() {
    int n;
    cin >> n;
    vector<string> words(n);
    for (int i = 0; i < n; i++) {
        cin >> words[i];
    }
    int maxWidth;
    cin >> maxWidth;
    vector<string> sol = Solution().fullJustify(words, maxWidth);
    for (int i = 0; i < sol.size(); i++) {
        cout << sol[i] << endl;
    }
    return 0;
}