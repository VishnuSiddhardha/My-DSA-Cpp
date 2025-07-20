#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string> &wordList)
    {
        unordered_set<string> st(wordList.begin(), wordList.end());
        st.erase(beginWord);
        vector<vector<string>> ans;
        queue<vector<string>> q;
        q.push({beginWord});
        int wordLen = beginWord.length();
        while (!q.empty())
        {
            int len = q.size();
            unordered_set<string> to_remove;
            for (int i = 0; i < len; i++)
            {
                vector<string> order = q.front();
                q.pop();
                string w = order.back();
                for (int j = 0; j < wordLen; j++) 
                {
                    char original = w[j];
                    for (char ch = 'a'; ch <= 'z'; ch++)
                    {
                        w[j] = ch;
                        if (w == endWord) {
                            order.push_back(endWord);
                            if (ans.size() != 0 && ans[0].size() < order.size()) return ans;
                            ans.push_back(order);
                            order.pop_back();
                        }
                        else if (st.find(w) != st.end()) {
                            to_remove.insert(w);
                            order.push_back(w);
                            q.push(order);
                            order.pop_back();
                        }
                    }
                    w[j] = original;
                }
            }
            for (string s : to_remove) {
                st.erase(s);
            }
        }
        return ans;
    }
};

int main()
{

    return 0;
}