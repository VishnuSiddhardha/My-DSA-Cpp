#include<bits/stdc++.h>
using namespace std;

int getLengthOfLongestSubString(string s, int k) 
{
    unordered_map<char, int> mp;
    int left = 0;
    int maxLen = 0;
    for (int end = 0; end < s.length(); end++)
    {
        mp[s[end]]++;
        if (mp.size() > k)
        {
            mp[s[left]]--;
            if (mp[s[left]] == 0)   mp.erase(s[left]);
            left++;
        }
        if (mp.size() <= k)
            maxLen = max(maxLen, end-left+1);
    }
    return maxLen;
}

int main()
{
    return 0;
}