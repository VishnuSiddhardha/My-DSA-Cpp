#include <bits/stdc++.h>
using namespace std;

void printSubSeq(vector<char> v, vector<char> temp, int len, int ind)
{
    if (ind == len)
    {
        for (char x : temp)
            cout << x << " ";
        cout << endl;
        return;
    }
    temp.push_back(v[ind]);
    printSubSeq(v, temp, len, ind + 1);
    temp.pop_back();
    printSubSeq(v, temp, len, ind + 1);
}

void callSub(vector<char> v)
{
    int len = v.size();
    vector<char> t;
    printSubSeq(v, t, len, 0);
}

int main()
{
    vector<char> arr = {'a', 'b', 'c', 'd'};
    callSub(arr);
    return 0;
}