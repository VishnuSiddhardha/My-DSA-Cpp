#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart)
    {
        vector<vector<int>> ans;
        int iters = 1;
        int rEnd, cEnd;
        rEnd = rStart;


        while (iters <= 4)
        {
            cEnd = cStart+iters;
            cout << "left to right" << endl;
            for(int i = cStart; i < cEnd; i++) // left to right, col changing
                cout << rStart << " " << i << endl;
            cStart = cEnd;
            rEnd = rStart+iters;
            cout << "top to bottom" << endl;
            for (int i = rStart; i < rEnd; i++) // top to bottom, row changing
                cout << i << " " << cStart << endl;
            rStart = rEnd;

            iters++;
            cEnd = cStart-iters;
            cout << "right to left" << endl;
            for (int i = cStart; i > cEnd; i--) //right to left, col changing
                cout << rStart << " " << i << endl;
            cStart = cEnd;
            rEnd = rStart-iters;
            cout << "bottom to top" << endl;
            for (int i = rStart; i >= rEnd; i--) // bottom to top, row changing
                cout << i << " " << cStart << endl;
            rStart = rEnd;
            cStart++;
            cout << "at last start: " << rStart << " " << cStart << endl;
            cout << "at last End: " << rEnd << " " << cEnd << endl;
            iters++;
        }
        return ans;
    }
};

int main()
{
    Solution obj;
    vector<vector<int>> res;
    res = obj.spiralMatrixIII(5,6,1,4);
    return 0;
}