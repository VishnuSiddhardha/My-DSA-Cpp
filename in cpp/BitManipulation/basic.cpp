#include <bits/stdc++.h>
using namespace std;

int main()
{
    int start = 10;
    int goal = 7;
    int flips = 0;
    while (start && goal)
    {
        if ((start & 1) != (goal & 1))
            flips++;
        start = start >> 1;
        goal = goal >> 1;
    }
    cout << start && goal;
    return 0;
}