#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int n;
    void helper(int op, int cl, string &s, vector<string> &res)
    {
        if (op == n && cl == n){
            res.push_back(s);
            return;
        }
        if (op < n) {
            s.push_back('(');
            helper(op+1, cl, s, res);
            s.pop_back();
        }
        if (cl < op) {
            s.push_back(')');
            helper(op, cl+1, s, res);
            s.pop_back();
        }
    }
public:
    vector<string> generateParenthesis(int n)
    {
        this->n = n;
        vector<string> res;
        string s;
        helper(0, 0, s, res);
        for (string &wd : res)
            cout << wd << " ";
    }
};

int main()
{
    Solution obj;
    obj.generateParenthesis(3);
    return 0;
}