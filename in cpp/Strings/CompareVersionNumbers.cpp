#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int compareVersion(string version1, string version2)
    {
        int n = version1.length(), m = version2.length();
        int i = 0, j = 0;

        while (i < n || j < m)
        {
            int num1 = 0, num2 = 0;
            
            while (i < n && version1[i] != '.')
            {
                num1 = num1*10 + (version1[i]-'0');
                i++;
            }
            i++;
            while (j < m && version2[j] != '.')
            {
                num2 = num2*10 + (version2[j]-'0');
                j++;
            }
            j++;

            if (num1 > num2) return 1;
            else if (num1 < num2) return -1;
        }
        return 0;
    }
};

int main()
{

    return 0;
}