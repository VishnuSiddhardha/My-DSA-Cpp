#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        int n = text.length(), m = brokenLetters.length();
        bool arr[26] = {false};

        for (char c : brokenLetters) arr[c-'a'] = true;
        int count = 0, i = 0;
        bool isPos = true;
        while (i < n) {
            while (i < n && text[i] != ' ') { // for every word
                if (arr[text[i]-'a']) isPos = false;
                i++;
            }
            if (isPos) count++;
            isPos = true;
            i++;
        }
        return count;
    }
};

int main() {
    
    return 0;
}