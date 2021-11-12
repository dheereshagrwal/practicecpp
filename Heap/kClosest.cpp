#include <bits/stdc++.h>
using namespace std;
void kClosest(int arr[], int n, int x, int k)
{
    priority_queue<pair<int, int>> maxh;
    for (int i = 0; i < n; i++)
    {
        maxh.push({abs(arr[i] - x), arr[i]});
        if (maxh.size() > k)
            maxh.pop();
    }
    while (maxh.size() > 0)
    {
        cout << maxh.top().second << " ";
        maxh.pop();
    }
}
int main(void)
{
    int arr[] = {4, 5, 6, 7, 8, 9, 10};
    kClosest(arr, 7, 7, 3);
}