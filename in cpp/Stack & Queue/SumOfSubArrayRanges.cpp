#include<bits/stdc++.h>
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

long long sumSubarrayMins(vector<int> &arr)
{
    long long sum = 0;
    vector<int> nextSmallArr = nextSmallerElementArray(arr);
    vector<int> prevSmallArr = prevSmallerElementArray(arr);
    for (int i = 0; i < arr.size(); i++)
    {
        int front = nextSmallArr[i] - i;
        int back = i - prevSmallArr[i];
        sum = (sum + (arr[i]*front*back));
    }
    return sum;
}

vector<int> nextGreaterElementArray(vector<int> arr)
{
    stack<int> st;
    vector<int> res(arr.size());
    int n = arr.size();
    for (int i = n-1; i >= 0; i--)
    {
        while (!st.empty() && arr[st.top()] <= arr[i]) {
            st.pop();
        }
        res[i] = st.empty() ? n : st.top();
        st.push(i);
    }
    return res;
}

vector<int> prevGreaterElementArray(vector<int> arr)
{
    stack<int> st;
    vector<int> res(arr.size());
    for (int i = 0; i < arr.size(); i++)
    {
        while (!st.empty() && arr[st.top()] < arr[i]) {
            st.pop();
        }
        res[i] = st.empty() ? -1 : st.top();
        st.push(i);
    }
    return res;
}

long long sumSubarrayMaxs(vector<int> &arr) {
    long long sum = 0;
    vector<int> nextSmallArr = nextGreaterElementArray(arr);
    vector<int> prevSmallArr = prevGreaterElementArray(arr);
    for (int i = 0; i < arr.size(); i++)
    {
        int front = nextSmallArr[i] - i;
        int back = i - prevSmallArr[i];
        sum = (sum + (arr[i]*front*back));
    }
    return sum;
}

long long subArrayRanges(vector<int>& nums) {
    return sumSubarrayMaxs(nums) - sumSubarrayMins(nums);
}

int main()
{
    vector<int> arr = {1,2,3};
    long long res = subArrayRanges(arr);
    cout << "Result: " << res << endl;
    return 0;
}