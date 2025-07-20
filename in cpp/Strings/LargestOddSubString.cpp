#include<bits/stdc++.h>
using namespace std;

string largestOddNumber(string num) {
    string result;
    string upto = "";
    for (int i = 0; i < num.length(); i++) {
        int ele = num[i] - '0';
        upto += num[i];
        if (ele % 2 == 1) result = upto;
    }
    return result;
}

int main()
{
    int x = 49 - '0';
    cout << x;
    return 0;
}