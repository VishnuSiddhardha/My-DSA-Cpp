#include<bits/stdc++.h>
using namespace std;

int myAtoi(string s) {
    int start = 0;
    int sign = 1;
    // remove leading spaces
    while (s[start] == ' ') start++;
    // check for sign;
    if (s[start] == '-' || s[start] == '+') {
        sign = s[start] == '-' ? -1 : 1;
        start++;
    }
    // remove leading 0's
    while (s[start] == '0') start++;
    int res = 0, nsPlace = 10;
    // now for every char
    for (int i = start; i < s.size(); i++)
    {
        if (s[i] == ' ') continue;
        else if (s[i] >= '0' && s[i] <= '9') {
            res = (res*nsPlace) + (s[i] - '0');
        }
        else
            break;
    }
    return sign*res;
}

int main()
{
    string s = "words and 987";
    int res = myAtoi(s);
    for (auto x : s)
        cout << x - '0' << " ";
    cout << endl;
    cout << "Result: " << res << endl;
    return 0;
}