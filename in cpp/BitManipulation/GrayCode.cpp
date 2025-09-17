#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> grayCode(int n)
    {
        vector<int> ans;
        int up = pow(2,n);
        for (int i = 0; i < up; i++)
        {
            cout << (i^(i>>1)) << endl;
            ans.push_back((i^(i>>1)));
            return ans;
        }
    }
};

int main()
{
    Solution obj;
    obj.grayCode(4);
    return 0;
}