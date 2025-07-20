#include <bits/stdc++.h>
using namespace std;

// O(n^2) - solution
// int area = 0;
// for (int i = 0; i < heights.size(); i++)
// {
//     int min_val = heights[i];
//     for (int j = i; j >= 0; j--)
//     {
//         min_val = min(min_val, heights[j]);
//         area = max(area, (i-j+1)*min_val);
//     }
// }
// return area;

vector<int> nextSmallerElementArray(vector<int> arr)
{
    stack<int> st;
    vector<int> res(arr.size());
    int n = arr.size();
    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && arr[st.top()] >= arr[i])
        {
            st.pop();
        }
        res[i] = st.empty() ? n : st.top();
        st.push(i);
    }
    return res;
}

vector<int> prevSmallerElementArray(vector<int> arr)
{
    stack<int> st;
    vector<int> res(arr.size());
    for (int i = 0; i < arr.size(); i++)
    {
        while (!st.empty() && arr[st.top()] >= arr[i])
        {
            st.pop();
        }
        res[i] = st.empty() ? -1 : st.top();
        st.push(i);
    }
    return res;
}

int largestRectangleArea2(vector<int> &heights)
{
    int area = 0;
    vector<int> nextSmallEle = nextSmallerElementArray(heights);
    vector<int> prevSmallEle = prevSmallerElementArray(heights);

    cout << "next Smaller:\n";
    for (auto x : nextSmallEle)
        cout << x << " ";
    cout << endl;
    cout << "prev Smaller:\n";
    for (auto x : prevSmallEle)
        cout << x << " ";
    cout << endl;
    for (int i = 0; i < heights.size(); i++)
    {
        int size = (nextSmallEle[i] - i) + (i - prevSmallEle[i]) - 1;
        area = max(area, size * heights[i]);
    }
    return area;
}

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

int main()
{
    vector<int> arr = {2, 2, 1, 5, 6, 2, 3};
    int res = largestRectangleArea(arr);
    cout << res << endl;
    return 0;
}