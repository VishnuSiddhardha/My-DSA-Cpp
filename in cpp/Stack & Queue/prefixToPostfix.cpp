#include<bits/stdc++.h>
using namespace std;

string preToPost(string s) {
    // Write your code here
    stack<string> st;
    int i = s.size()-1; 
    while (i >= 0)
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
            string result = opd1 + opd2 + s[i];
            st.push(result);
        }
        i--;
    }
    return st.top();
}

int main()
{
    string s = "ABC/-AK/L-*";
    string res = preToPost(s);
    cout << res << endl;
    return 0;
}