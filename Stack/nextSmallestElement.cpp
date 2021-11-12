#include <bits/stdc++.h>
using namespace std;
vector<int> nextSmallestElement(vector<int> arr, int n)
{
    vector<int> v; // creating a vector for storing result
    stack<int> s;  // creating a stack for temp. hold the values from array
    for (int i = n - 1; i >= 0; i--)
    {

        if (s.size() > 0)
            while (s.size() > 0 && s.top() >= arr[i])
                s.pop();
        if (s.size() == 0)
            v.push_back(-1);
        else
            v.push_back(s.top());
        s.push(arr[i]); // push array in stack
    }
    reverse(v.begin(), v.end()); // while returning reverse the vector and return it.
    return v;
}

int main(void)
{
    vector<int> arr;
    arr.push_back(11);
    arr.push_back(13);
    arr.push_back(21);
    arr.push_back(3);

    vector<int> v = nextSmallestElement(arr, 4);
    for (int i = 0; i < 4; i++)
        cout << arr[i] << " --> " << v[i] << endl;
    cout << endl;
}
