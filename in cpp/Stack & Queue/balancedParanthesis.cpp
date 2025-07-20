#include <bits/stdc++.h>
using namespace std;

bool isValid(string s)
{
    stack<char> st;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[')
            st.push(s[i]);
        else
        {
            if (st.empty())
                return false;
            char check = st.top();
            st.pop();
            if (s[i] == ')' && check == '(')
                continue;
            else if (s[i] == '}' && check == '{')
                continue;
            else if (s[i] == ']' && check == '[')
                continue;
            else
                return false;
        }
    }
    if (!st.empty()) return false;
    return true;
}

int main()
{
    return 0;
}