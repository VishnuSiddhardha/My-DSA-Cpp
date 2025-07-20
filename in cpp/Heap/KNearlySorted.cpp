#include <bits/stdc++.h>
using namespace std;

void nearlySorted(vector<int> &arr, int k)
{
    // code
    int curSize = 0, sortInd = 0, i = 0;
    priority_queue<int,vector<int>,greater<int>> pq;

    // insert 1st k elements
    for (int i = 0; i < k; i++) 
        pq.push(arr[i]);
    int ind = 0;
    // start the logic
    for (int i = k; i < arr.size(); i++) {
        pq.push(arr[i]);
        arr[ind] = pq.top();
        pq.pop();
        ind++;
    }
    // for remaining elements
    while (!pq.empty()) {
        arr[ind] = pq.top();
        ind++;
        pq.pop();
    }
}

int main()
{
    vector<int> arr = {1, 4, 5, 2, 3, 6, 7, 8, 9, 10};
    cout << "Elements before sorting:\n";
    for (int x : arr)
        cout << x << " ";
    cout << endl;
    nearlySorted(arr, 2);
    cout << "Elements after sorting:\n";
    for (int x : arr)
        cout << x << " ";
    cout << endl;
    nearlySorted(arr, 3);
    return 0;
}