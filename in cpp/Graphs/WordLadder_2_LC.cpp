#include <bits/stdc++.h>
using namespace std;

class Solution
{
    unordered_map<string, int> mp;
    vector<vector<string>> ans;
    string b;
    void backTrack(string w, vector<string> &order)
    {
        if (w == b) {
            reverse(order.begin(), order.end());
            ans.push_back(order);
            reverse(order.begin(), order.end());
            return;
        }
        int len = w.length();
        int steps = mp[w];
        for (int i = 0; i < len; i++) {
                char original = w[i];
                for (char ch = 'a'; ch <= 'z'; ch++) {
                    w[i] = ch;
                    if (mp.find(w) != mp.end() && mp[w]+1 == steps) {
                        order.push_back(w);
                        backTrack(w, order);
                        order.pop_back();
                    }
                }
                w[i] = original;
            }
    }
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string> &wordList)
    {
        unordered_set<string> st(wordList.begin(), wordList.end());
        st.erase(beginWord);
        b = beginWord;
        int len = beginWord.length();
        queue<string> q;
        q.push(beginWord);
        mp[beginWord] = 1;
        while (!q.empty())
        {
            string w = q.front();
            int level = mp[w];
            q.pop();
            if (w == endWord) break;
            for (int i = 0; i < len; i++) {
                char original = w[i];
                for (char ch = 'a'; ch <= 'z'; ch++) {
                    w[i] = ch;
                    if (st.find(w) != st.end()) {
                        q.push(w);
                        st.erase(w);
                        mp[w] = level+1;
                    }
                }
                w[i] = original;
            }
        }
        if (mp.find(endWord) == mp.end()) return ans;
        vector<string> ord;
        ord.push_back(endWord);
        backTrack(endWord, ord);
        return ans;
    }
};

int main()
{

    return 0;
}