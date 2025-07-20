#include <bits/stdc++.h>
using namespace std;

int getPrecedence(char c)
{
    if (c == '^')
        return 3;
    else if (c == '*' || c == '/')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return -1;
}

string infixToPostfix(string &s)
{
    // code here
    string result = "";
    stack<char> st;
    int i = 0;
    while (i < s.length())
    {
        if ((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '1' && s[i] <= '9'))
        {
            result += s[i];
        }
        else if (s[i] == '(')
        {
            st.push('(');
        }
        else if (s[i] == ')')
        {
            while (st.top() != '(')
            {
                result += st.top();
                st.pop();
            }
            st.pop();
        }
        else
        {
            while (!st.empty() && getPrecedence(s[i]) <= getPrecedence(st.top()))
            {
                result += st.top();
                st.pop();
            }
            st.push(s[i]);
        }
        cout << s[i] << endl;
        i++;
    }
    // for remaining elements in stack - if remains
    while (!st.empty())
    {
        result += st.top();
        st.pop();
    }
    return result;
}

int main()
{
    string s = "a+b*(c^d-e)^(f+g*h)-i";
    string res = infixToPostfix(s);
    cout << s << endl;
    return 0;
}