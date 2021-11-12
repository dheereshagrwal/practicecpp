#include <bits/stdc++.h>
using namespace std;
int main(void)
{
    int m = 4;
    int k = 2;
    int arr[][2] = {{1, 3}, {-2, 2}, {5, 8}, {0, 1}};
    priority_queue<pair<int, pair<int, int>>> maxh;
    for (int i = 0; i < m; i++)
    {
        maxh.push({arr[i][0] * arr[i][0] + arr[i][1] * arr[i][1], {arr[i][0], arr[i][1]}});
        if (maxh.size() > k)
            maxh.pop();
    }
    while (maxh.size() > 0)
    {
        cout << maxh.top().second.first << " " << maxh.top().second.second << endl;
        maxh.pop();
    }
}