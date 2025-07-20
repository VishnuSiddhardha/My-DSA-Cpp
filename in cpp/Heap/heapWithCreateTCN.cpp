#include<bits/stdc++.h>
using namespace std;

void heapfy(int *arr, int size, int ind) {
    
    while (2*ind + 1 < size) {
        int left = 2*ind+1;
        int right = 2*ind+2;
        int largest = ind;

        if (arr[largest] < arr[left]) largest = left;
        if ((right < size) && (arr[largest] < arr[right])) largest = right;
        if (largest == ind) break;
        swap(arr[ind], arr[largest]);
        ind = largest;
    }
}

void buildMaxHeap(int *arr, int size)
{
    int ind = size/2 + 1;
    while (ind >= 0) {
        heapfy(arr, size, ind);
        ind--;
    }
}


int main()
{
    int arr[] = {10,20,30,40,50,60,70,80,90};
    cout << "elements before building heap:\n";
    for (auto x : arr) 
        cout << x << " ";
    cout << endl;
    buildMaxHeap(arr, 9);
    cout << "elements after building heap:\n";
    for (auto x : arr) 
        cout << x << " ";
    return 0;
}