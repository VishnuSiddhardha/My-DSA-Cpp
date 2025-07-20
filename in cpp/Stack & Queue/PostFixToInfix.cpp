#include<bits/stdc++.h>
using namespace std;

string postToInfix(string s) {
    // Write your code here
    stack<string> st;
    int i = 0; 
    while (i < s.size())
    {
        if ((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '1' && s[i] <= '9'))
        {
            string temp = "";
            temp = s[i];
            cout << temp << endl;
            st.push(temp);
        }
        else {
            string opd1 = st.top();
            st.pop();
            string opd2 = st.top();
            st.pop();
            string result = '(' + opd2 + s[i] + opd1 + ')';
            st.push(result);
        }
        i++;
    }
    return st.top();
}

int main()
{
    string s = "ab*c+";
    string res = postToInfix(s);
    cout << res << endl;
    return 0;
}