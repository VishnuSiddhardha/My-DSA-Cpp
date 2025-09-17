#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool doesAliceWin(string s)
    {
        vector<bool> vowels(26, false);
        for (char ch : "aeiou") vowels[ch-'a'] = true;
        
        int count = 0;
        for (char &ch : s) {
            if (vowels[ch-'a']) count++;
        }
        return count != 0;
    }
};

int main()
{

    return 0;
}