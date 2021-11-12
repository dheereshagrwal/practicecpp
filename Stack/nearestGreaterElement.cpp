#include <bits/stdc++.h>
using namespace std;
vector<int> nearestGreaterElement(vector<int> arr, int n)
{

    vector<int> v; // creating a vector for storing result
    stack<int> s;  // creating a stack for temp. hold the values from array
    for (int i = 0; i < n; i++)
    {
        if (s.size() == 0)
            v.push_back(-1);
        else if (s.size() > 0 && s.top() > arr[i])
            v.push_back(s.top());
        else if (s.size() > 0 && s.top() <= arr[i])
            while (s.size() > 0 && s.top() <= arr[i])
                s.pop();
        if (s.size() == 0)
            v.push_back(-1);
        else
            v.push_back(s.top());
        s.push(arr[i]); // push array in stack
    }
    return v;
}