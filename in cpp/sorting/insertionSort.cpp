#include<bits/stdc++.h>
using namespace std;

void InsertionSort(vector<int> &arr)
{
    int i, j, temp;
    for (i = 1; i < arr.size(); i++)
    {
        temp = arr[i];
        for (j = i-1; j >= 0; j--)
        {
            if (arr[j] > temp) {
                arr[j+1] = arr[j];
            }
            else break;
        }
        arr[j+1] = temp;
    }
}

int main()
{
    vector<int> arr = {5,4,3,2,1,1,2,3,4,54,3,5,3,3,5,3,3,6,3,6,7,8,5,2,2,47,3};
    for (int x : arr)
        cout << x << " ";
    cout << endl;

    InsertionSort(arr);

    for (int x : arr)
        cout << x << " ";
    cout << endl;


    return 0;
}