#include <bits/stdc++.h>
using namespace std;

vector<int> twoSum(vector<int> &numbers, int target)
{
    int i = 0, j = numbers.size()-1;
    while (i < j)
    {
        if (numbers[i] + numbers[j] == target)
            break;
        else if (numbers[i] + numbers[j] > target)
            j--;
        else
            i++;
    }
    vector<int> res = {i+1, j+1};
    return res;
}

int main()
{

    return 0;
}