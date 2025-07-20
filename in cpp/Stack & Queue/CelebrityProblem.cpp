#include <bits/stdc++.h>
using namespace std;

int celebrity(vector<vector<int>> &mat)
{
    // code here
    int top = 0, down = mat.size()-1;
    while (top < down)
    {
        if (mat[top][down] == 1)
            top++;
        else if (mat[down][top] == 1)
            down--;
        else {
            top++;
            down--;
        }
    }
    if (top > down)
        return -1;
    for (int i = 0; i < mat[0].size(); i++)
        if ((i != top && mat[top][i] == 1) || mat[i][top] == 0)
            return -1;
    return top;
}

int main()
{
    vector<vector<int>> mat = {{1, 1, 0}, {0, 1, 0}, {0, 1, 1}};
    int k = celebrity(mat);
    cout << k << endl;
    return 0;
}