#include <bits/stdc++.h>
using namespace std;
int minDiffEle(int arr[], int start, int end, int ele)
{
    int res = -1;
    int mn = INT_MAX;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (arr[mid] == ele)
            res = arr[mid];
        else if (ele > arr[mid])
            start = mid + 1;
        else
            end = mid - 1;
    }
    mn = min(abs(arr[start] - ele), abs(arr[end] - ele));
    return mn == abs(arr[start] - ele) ? arr[start] : arr[end];
}
int main(void)
{
    int arr[] = {4, 6, 10};
    int n = *(&arr + 1) - arr;
    cout << minDiffEle(arr, 0, n - 1, 7);
    cout << endl;
}