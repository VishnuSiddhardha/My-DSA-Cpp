#include<bits/stdc++.h>
using namespace std;

string removeKdigits(string num, int k) {
    stack<char> st;
    int i = 0;
    while (i < num.length())
    {
        cout << "i: " << i << endl;
        cout << "Value of k: " << k << endl;
        while (!st.empty() && (k > 0) && ((st.top()-num[i]) > 0))
        {
            st.pop();
            k--;
        }
        st.push(num[i]);
        i++;
    }
    while (k > 0) {
        st.pop();
        k--;
    }
    if (st.empty()) return "0";
    string res = "";
    while (!st.empty()) {
        res += st.top();
        st.pop();
    }
    while (res.size() != 0 && res.back() == '0')
        res.pop_back();
    if (res.empty()) return "0";
    reverse(res.begin(), res.end());
    return res;
}



int main()
{
    string str = "";
    cout << str.front();
    // string res = removeKdigits(str, 2);
    // cout << res << endl;
    return 0;
}