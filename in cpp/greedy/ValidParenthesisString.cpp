#include <bits/stdc++.h>
using namespace std;

bool checkValidString(string s)
{
    int mini = 0, maxi = 0;
    for (char x : s)
    {
        if (x == '(') {
            mini++;
            maxi++;
        }
        else if (x == ')') {
            mini--;
            maxi--;
        }
        else {
            mini--;
            maxi++;
        }
        if (mini < 0) mini = 0;
        if (maxi == 0) return false;
    }
    return mini == 0;
}

int main()
{
    return 0;
}