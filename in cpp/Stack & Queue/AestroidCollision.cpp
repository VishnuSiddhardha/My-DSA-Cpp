#include <bits/stdc++.h>
using namespace std;

vector<int> asteroidCollision(vector<int> &asteroids)
{
    vector<int> res;
    for (int i = 0; i <asteroids.size(); i++)
    {
        if (asteroids[i] > 0)
        {
            res.push_back(asteroids[i]);
        }
        else
        {
            while (!res.empty() && (res.back() > 0) && (res.back() < abs(asteroids[i])))
                res.pop_back();
            
            if (!res.empty() && res.back() == abs(asteroids[i]))
                res.pop_back();
            else if (res.empty() || res.back() < 0)
                res.push_back(asteroids[i]);

        }
    }
    return res;
}

int main()
{
    vector<int> arr = {-2, -2, 1, -2};
    vector<int> result = asteroidCollision(arr);
    for (int x : result)
        cout << x << " ";
    return 0;
}