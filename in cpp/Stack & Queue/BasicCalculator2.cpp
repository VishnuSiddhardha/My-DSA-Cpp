#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // we don't even need a stack also, 
    // we can directly do it
    int calculate(string s) {
        stack<int> st;
        int num = 0;
        char op = '+'; // Initialize with '+' so first number gets pushed
        int n = s.length();

        for (int i = 0; i < n; ++i) {
            char ch = s[i];

            if (isdigit(ch)) {
                num = num * 10 + (ch - '0');
            }

            // If current char is operator or end of string
            if ((!isdigit(ch) && ch != ' ') || i == n - 1) {
                if (op == '+') {
                    st.push(num);
                } else if (op == '-') {
                    st.push(-num);
                } else if (op == '*') {
                    int temp = st.top(); st.pop();
                    st.push(temp * num);
                } else if (op == '/') {
                    int temp = st.top(); st.pop();
                    st.push(temp / num);
                }
                op = ch;
                num = 0;
            }
        }

        int result = 0;
        while (!st.empty()) {
            result += st.top();
            st.pop();
        }

        return result;
    }
};


class Solution
{
    int makeOperation(char op, int num1, int num2)
    {
        switch (op)
        {
        case '+':
            return num1 + num2;
        case '-':
            return num1 - num2;
        case '*':
            return num1 * num2;
        case '/':
            return num1 / num2;
        }
    }

public:
    int calculate(string s)
    {
        int n = s.size();
        stack<char> oper;
        stack<int> data;
        unordered_map<char, int> precd;
        precd.insert({'+', 1});
        precd.insert({'-', 1});
        precd.insert({'*', 2});
        precd.insert({'/', 2});

        int number = 0;
        for (int i = 0; i < n; i++)
        {
            char ch = s[i];
            if (isdigit(ch))
            {
                number = number * 10 + (s[i] - '0');
            }
            else if (ch != ' ')
            {
                data.push(number);
                number = 0;
                if (oper.empty() || precd[ch] > precd[oper.top()])
                {

                    oper.push(ch);
                }
                else
                {
                    while (!oper.empty() && precd[ch] <= precd[oper.top()])
                    {
                        int op = oper.top();
                        oper.pop();
                        int num2 = data.top();
                        data.pop();
                        int num1 = data.top();
                        data.pop();
                        int res = makeOperation(op, num1, num2);
                        data.push(res);
                    }
                    oper.push(ch);
                }
            }
        }
        data.push(number);
        cout << "data size: " << data.size() << endl;
        cout << "oper size: " << oper.size() << endl;
        while (!oper.empty())
        {
            int op = oper.top();
            oper.pop();
            int num2 = data.top();
            data.pop();
            int num1 = data.top();
            data.pop();
            int res = makeOperation(op, num1, num2);
            data.push(res);
        }
        int result = data.top();
        return result;
    }
};

int main()
{
    string s = "3+2* 2";
    Solution obj;
    cout << obj.calculate(s);

    return 0;
}