#include<bits/stdc++.h>
using namespace std;

int lengthOfLongestSubstring(string s) {
    int maxLength = 0;
    int hashMap[256];
    for (int i = 0; i < 256; i++)
        hashMap[i] = -1;
    int start = 0;
    for (int j = 0; j < s.length(); j++)
    {
        if (hashMap[s[j]] != -1)
        {
            if (hashMap[s[j]] >= start) {
                start = hashMap[s[j]] + 1;
            }
        }
        maxLength = max(maxLength, j-start+1);
        hashMap[s[j]] = j;
    } 
    return maxLength;
}

int main()
{
    int len = lengthOfLongestSubstring("abcabcbb");
    cout << len;
    return 0;
}