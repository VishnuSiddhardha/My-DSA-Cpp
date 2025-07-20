#include <bits/stdc++.h>
using namespace std;

vector<int> prevSmaller(vector<int> &A)
{
    vector<int> arr(A.size());
    stack<int> st;
    for (int i = 0; i < A.size(); i++)
    {
        while (!st.empty() && st.top() >= A[i])
            st.pop();
        if (st.empty())
            arr[i] = -1;
        else
            arr[i] = st.top();

        st.push(A[i]);
    }
    return arr;
}

int main()
{
    vector<int> arr = {39, 27, 11, 4, 24, 32, 32, 1 };
    vector<int> res = prevSmaller(arr);
    for (auto x: res)
        cout << x << " ";
    return 0;
}