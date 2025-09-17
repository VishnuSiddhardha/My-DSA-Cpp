#include<bits/stdc++.h>
using namespace std;

vector<int> nextGreaterPermutation(vector<int> &A) {
    // Write your code here.
    int n = A.size();
    int ind= -1;
    for (int i = n-2; i >= 0; --i)
    {
        if (A[i] < A[i+1])
        {
            ind = i;
            cout << "index is ->" << ind << endl;
            break;
        }
    }
    if (ind == -1) {
        reverse(A.begin(),A.end());
    }
    else {
        int miniIndex;
        for (int i = n-1; i > ind; --i) {
            if (A[ind] < A[i]) {
                miniIndex = i;
                break;
            }
        }
        cout << "Swapping-> arr[ind] , mini " << A[ind] << " " << A[miniIndex] << endl;
        swap(A[ind],A[miniIndex]);
        reverse(A.begin()+ind+1,A.end());
    }
    return A;
}

int main()
{
    vector<int> arr = {6, 10 ,8 ,13, 13};
    vector<int> result = nextGreaterPermutation(arr);
    for (int x : result)
        cout << x << " ";
    return 0;
}