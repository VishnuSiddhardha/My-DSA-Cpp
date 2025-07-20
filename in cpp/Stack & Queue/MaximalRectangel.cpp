#include <bits/stdc++.h>
using namespace std;

int largestRectangleArea(vector<int> &heights)
{
    int area = 0;
    stack<int> st;
    for (int i = 0; i < heights.size(); i++)
    {
        if (!st.empty() && heights[st.top()] > heights[i])
        {
            while (!st.empty() && heights[st.top()] > heights[i])
            {
                int ele = heights[st.top()];
                st.pop();
                int back = st.empty() ? -1 : st.top();
                area = max(area, ele * (i - back - 1));
            }
        }
        st.push(i);
    }
    while (!st.empty())
    {
        int front = heights.size();
        int ele = heights[st.top()];
        st.pop();
        int back = st.empty() ? -1 : st.top();
        area = max(area, ele * (front - back - 1));
    }
    return area;
}

int maximalRectangle(vector<vector<char>> &matrix)
{
    vector<vector<int>> prefixSum(matrix.size(), vector<int>(matrix[0].size()));
    int area = 0;
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[0].size(); j++)
        {
            if (matrix[i][j] == '0')
                prefixSum[i][j] = 0;
            else {
                if (i==0) prefixSum[i][j] = 1;
                else prefixSum[i][j] = prefixSum[i-1][j] + 1;
            }
        }
        area = max(area, largestRectangleArea(prefixSum[i]));
    }
    return area;
}

int main()
{
    vector<vector<char>> mat = {{"1","0","1","0","0"},{"1","0","1","1","1"},{"1","1","1","1","1"},{"1","0","0","1","0"}};
    int res = maximalRectangle(mat);
    cout << res << endl;
    return 0;
}