#include <bits/stdc++.h>
using namespace std;

vector<int> findTwoElement(vector<int> &arr)
{
    // code here
    vector<int> result(2);
    int maxi = arr.size();
    int ind;
    for (int i = 0; i < maxi; i++)
        arr[i]--;
    cout << "after\n";
    for (int x : arr)
        cout << x << " ";
    cout << endl;
    for (int i = 0; i < maxi; i++)
    {
        if (arr[i] >= maxi)
        {
            ind = arr[i] % maxi;
        }
        else
            ind = arr[i];
        arr[ind] = ((arr[ind] / maxi + 1) * maxi) + (arr[ind] % maxi);
    }
    cout << "after\n";
    for (int x : arr)
        cout << x << " ";
    cout << endl;
    for (int i = 0; i < maxi; i++)
    {
        if (arr[i] < maxi)
            result[1] = i + 1;
        else if (arr[i] / maxi == 2)
        {
            result[0] = i + 1;
            cout << "entered this\n";
        }
    }

    return result;
}

int main()
{
    vector<int> elements = {6, 5, 8, 7, 1, 4, 1, 3, 2};
    vector<int> result = findTwoElement(elements);
    for (int i : result)
        cout << i << " ";
    return 0;
}