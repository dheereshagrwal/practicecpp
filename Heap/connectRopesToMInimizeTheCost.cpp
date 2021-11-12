#include <bits/stdc++.h>
using namespace std;
int connectRopesToMInimizeTheCost(int arr[], int n)
{

    priority_queue<int, vector<int>, greater<int>> minh;
    int cost = 0;
    for (int i = 0; i < n; i++)
        minh.push(arr[i]);

    while (minh.size() >= 2)
    {
        int first = minh.top();
        minh.pop();
        int second = minh.top();
        minh.pop();
        cost = cost + first + second;
        minh.push(first + second);
    }
    return cost;
}
int main(void)
{
    int arr[] = {1, 2, 3, 4, 5};
    cout << connectRopesToMInimizeTheCost(arr, 5) << endl;
}