#include<bits/stdc++.h>
using namespace std;

string preToInfix(string s)
{
    // Write your code here
    stack<string> st;
    int i = s.length()-1; 
    while (i >= 0)
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
            string result = '(' + opd1 + s[i] + opd2 + ')';
            st.push(result);
        }
        i--;
    }
    return st.top();
}

int main()
{
    string s = "*-A/BC-/AKL";
    string res = preToInfix(s);
    cout << res << endl;

    return 0;
}