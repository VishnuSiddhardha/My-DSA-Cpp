#include <bits/stdc++.h>
using namespace std;

// another approch - cleaner version said by chatgpt
#include <sstream>
class Solution {
public:
    bool wordPattern(string pattern, string s) {
        istringstream iss(s);
        unordered_map<char, string> mp;
        unordered_set<string> usedWords;
        
        string word;
        int i = 0;
        
        while (iss >> word) {
            if (i >= pattern.length()) return false; // more words than pattern chars
            
            char ch = pattern[i];
            
            if (mp.find(ch) != mp.end()) {
                if (mp[ch] != word) return false;
            } else {
                if (usedWords.count(word)) return false;
                mp[ch] = word;
                usedWords.insert(word);
            }
            i++;
        }
        
        return i == pattern.length(); // pattern must be fully used
    }
};


class Solution
{
public:
    bool wordPattern(string pattern, string s)
    {
        int n = s.length();
        string curWord = "";
        unordered_map<char, string> mp;
        unordered_set<string> st;
        int it = 0;
        for (int i = 0; i <= n; i++)
        {
            if (s[i] == ' ' || s[i] == '\0')
            {
                if (mp.find(pattern[it]) != mp.end()){
                    if (mp[pattern[it]] != curWord)
                        return false;
                }
                else {
                    if (st.find(curWord) != st.end()) return false;
                    mp[pattern[it]] = curWord;
                    st.insert(curWord);
                }
                curWord = "";
                it++;
            }
            else {
                curWord.push_back(s[i]);
            }
        }
        return it == pattern.size();
    }
};

int main()
{

    return 0;
}