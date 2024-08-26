#include <bits/stdc++.h>
using namespace std;

class Solution {
    vector<string> less20 = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
    vector<string> tens = {"", "Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
    vector<string> thousands = {"", "Thousand", "Million", "Billion"};
    string rec(int num) {
        if (num == 0) return "";
        if (num < 20) {
            return less20[num] + " ";
        } else if (num < 100) {
            return tens[num / 10] + " " + rec(num % 10);
        } else {
            return less20[num / 100] + " Hundred " + rec(num % 100); 
        }
    }
public:
    string numberToWords(int num) {
        if (num == 0) return "Zero";
        int i = 0;
        string sol = "";
        while (num > 0) {
            if (num % 1000 != 0) {
                sol = rec(num % 1000) + thousands[i] + " " + sol;
            }
            i++;
            num /= 1000;
        }
        while (sol[sol.length() - 1] == ' ')
            sol.pop_back();
        return sol;
    }
};