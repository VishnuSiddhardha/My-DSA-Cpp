#include <bits/stdc++.h>
using namespace std;

vector<int> nextSmallerElementArray(vector<int> arr)
{
    stack<int> st;
    vector<int> res(arr.size());
    int n = arr.size();
    for (int i = n-1; i >= 0; i--)
    {
        while (!st.empty() && arr[st.top()] >= arr[i]) {
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
        while (!st.empty() && arr[st.top()] > arr[i]) {
            st.pop();
        }
        res[i] = st.empty() ? -1 : st.top();
        st.push(i);
    }
    return res;
}

int sumSubarrayMins(vector<int> &arr)
{
    int mod = 1e9 + 7;
    int sum = 0;
    vector<int> nextSmallArr = nextSmallerElementArray(arr);
    vector<int> prevSmallArr = prevSmallerElementArray(arr);
    cout << "Smaller:\n";
    for (auto x : nextSmallArr)
        cout << x << " ";
    cout << endl;
    cout << "prev Smaller:\n";
    for (auto x : prevSmallArr)
        cout << x << " ";
    cout << endl;
    for (int i = 0; i < arr.size(); i++)
    {
        int front = nextSmallArr[i] - i;
        int back = i - prevSmallArr[i];
        cout << "sum: " << sum << endl;
        sum = (sum + (arr[i]*front*back)%mod)%mod;
    }
    return sum;
}

int main()
{
    vector<int> arr = {36,74,84,92,17,68,97,6,68,85};
    int sum = sumSubarrayMins(arr);
    cout << "Sum: " << sum << endl;
    // vector<int> arr = {1,1};
    // vector<int> res = nextSmallerElementArray(arr);
    // for (int i = 0; i < arr.size(); i++)
    //     cout << "Cur ele: " << arr[i] << ", its res[i]: " << res[i]<< endl;
    // cout << endl;
    // vector<int> res = prevSmallerElementArray(arr);
    // for (int i = 0; i < arr.size(); i++)
    //     cout << "Cur ele: " << arr[i] << ", its res[i]: " << res[i]<< endl;
    // cout << endl;
    return 0;
}