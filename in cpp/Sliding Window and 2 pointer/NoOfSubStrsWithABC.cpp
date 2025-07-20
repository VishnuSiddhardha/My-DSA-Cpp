#include<bits/stdc++.h>
using namespace std;

int numberOfSubstrings(string s) 
{
    int hashMap[3] = {-1, -1, -1};
    int count = 0;
    for (int i = 0; i < s.length(); i++)
    {
        hashMap[s[i]-'a'] = i;
        if (hashMap[0] != -1 && hashMap[1] != -1 && hashMap[2] != -1)
            count += 1 + min(hashMap[0], min(hashMap[1], hashMap[2]));
    }
    return count;
}

int main()
{
    string s = "abcabc";
    int numOfsubstrs = numberOfSubstrings(s);
    cout << numOfsubstrs << endl;
    return 0;
}