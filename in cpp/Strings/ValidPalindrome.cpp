#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isPalindrome(string s)
    {
        int l = 0, r = s.length()-1; // left & right

        while (l < r)
        {
            while(l < r && !isalnum(s[l])) l++;
            while(l < r && !isalnum(s[r])) r--;
            if(l < r && tolower(s[l]) != tolower(s[r]))
                return false;
            l++;
            r--;
        }
        return true;
    }
};

int main()
{
    Solution obj;
    obj.isPalindrome("A man, a plan, a canal: Panama");
    return 0;
}