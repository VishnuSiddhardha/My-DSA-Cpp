#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int ladderLength(string beginWord, string endWord, vector<string> &wordList)
    {
        unordered_set<string> st(wordList.begin(), wordList.end());
        st.erase(beginWord);
        int len = beginWord.length();
        queue<pair<string, int>> q;
        q.push({beginWord, 1});
        while (!q.empty())
        {
            string w = q.front().first;
            int level = q.front().second;
            q.pop();
            if (w == endWord) {
                return level;
            }
            for (int i = 0; i < len; i++) {
                char original = w[i];
                for (char ch = 'a'; ch <= 'z'; ch++) {
                    w[i] = ch;
                    if (st.find(w) != st.end()) {
                        q.push({w, level+1});
                        st.erase(w);
                    }
                }
                w[i] = original;
            }
        }
        return 0;
    }
};

int main()
{
    Solution obj;
    vector<string> words = {"hot","dot","dog","lot","log","cog"};
    obj.ladderLength("hit", "cog", words);
    return 0;
}