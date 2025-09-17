#include <bits/stdc++.h>
using namespace std;

class Solution
{
    char evaluate(char op, int t, int f){
        if (op == '&') return (!f) ? 't' : 'f';
        else if (op == '|') t ? 't' : 'f';
        else t ? 'f' : 't';
    }
    
public:
    bool parseBoolExpr(string expression)
    {
        stack<char> st;
        for (char ch : expression)
        {

            if (ch == ')')
            {
                int t = 0, f = 0;
                while (st.top() != '(') {
                   if (st.top() == 't') t++;
                   else f++;
                    st.pop();
                }
                st.pop();
                char toInsert = evaluate(st.top(), t, f);
                st.pop();
                st.push(toInsert);
            }
            else if (ch != ','){
                st.push(ch);
            }
        }
        if (st.top() == 't') return true;
        return false;
    }
};

int main()
{
    string s = "!(&(f,t))";
    Solution obj;
    cout << obj.parseBoolExpr(s);
    return 0;
}