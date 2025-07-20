#include <bits/stdc++.h>
using namespace std;

bool isMaxHeap(int arr[], int n)
{
    // Your code goes here
    for (int i = 0; i <= (n/2)-1; i++) {
        int left = 2*i+1;
        int right = 2*i+2;
        if ((arr[i] >= arr[left])) {
            cout << "comparing: " << arr[i] << " " << arr[left] << endl;
            if ((right >= n) || (right<n && arr[i] >= arr[right])) {
                cout << "Entered this\n";
                continue;
            }
        }
        cout << "i: " << i << endl;
        return false;
    }
    return true;
}

int main()
{
    int arr[] = {90, 15, 10, 7, 12, 2};
    if (isMaxHeap(arr, 6))
        cout << "yesss";
    else
        cout << "nOOOO";
    return 0;
}