#include<bits/stdc++.h>
using namespace std;

int characterReplacement(string s, int k) 
{
    vector<int> countArr(26, 0);
    int left = 0, maxFreq = 0;
    int len = 0;
    for (int right = 0; right < s.length(); right++)
    {
        len++;
        countArr[s[right] - 'A']++;
        maxFreq = max(maxFreq, countArr[s[right] - 'A']);
        if (len-maxFreq > k) {
            len--;
            countArr[s[left]-'A']--;
            left--;
        }    
    }
    return len;
}

int main()
{
    string s = "AABA";
    int len = characterReplacement(s, 2);
    cout << len << endl;
    return 0;
}