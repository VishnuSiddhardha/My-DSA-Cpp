#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string smallestSubsequence(string s)
    {
        int n = s.size();
        vector<int> lastIndex(26);
        for (int i = 0; i < n; i++)
            lastIndex[s[i] - 'a'] = i;
        vector<bool> visited(26, false);

        stack<char> st;
        for (int i = 0; i < n; i++)
        {  
            char c = s[i];
            if(visited[c-'a']) continue;
            // pop if there are any greater characters first 
            // than the current and are avaliable later use
            while (!st.empty() && c < st.top() && lastIndex[st.top()-'a'] > i)
            {
                visited[st.top()-'a'] = false;
                st.pop();
            }

            st.push(c);
            visited[c-'a'] = true; 
        }
        string res;
        while(!st.empty()) {
            res.push_back(st.top());
            st.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

int main()
{

    return 0;
}