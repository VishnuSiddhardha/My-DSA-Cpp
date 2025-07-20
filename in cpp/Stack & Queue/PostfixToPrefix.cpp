#include<bits/stdc++.h>
using namespace std;

string postToPre(string s) {
    // Write your code here
    stack<string> st;
    int i = 0; 
    while (i < s.size())
    {
        if ((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '1' && s[i] <= '9'))
        {
            string temp = "";
            temp = s[i];
            st.push(temp);
        }
        else {
            string opd1 = st.top();
            st.pop();
            string opd2 = st.top();
            st.pop();
            string result = s[i] + opd2 + opd1 ;
            st.push(result);
        }
        i++;
    }
    return st.top();
}

int main()
{
    string s = "ABC/-AK/L-*";
    string res = postToPre(s);
    cout << res << endl;
    return 0;
}