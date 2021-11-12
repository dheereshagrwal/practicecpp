#include <bits/stdc++.h>
using namespace std;
int floorVal(int arr[], int start, int end, int ele)
{
    int res = -1;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (ele == arr[mid])
            return arr[mid];
        if (ele > arr[mid])
        {
            res = arr[mid];
            start = mid + 1;
        }
        else if (ele < arr[mid])
            end = mid - 1;
    }
    return res;
}
int ceilVal(int arr[], int start, int end, int ele)
{
    int res = -1;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (ele == arr[mid])
            return arr[mid];
        if (ele < arr[mid])
        {
            res = arr[mid];
            end = mid - 1;
        }
        else if (ele > arr[mid])
            start = mid + 1;
    }
    return res;
}
int main(void)
{
    int arr[] = {1, 2, 3, 4, 8, 10, 10, 12, 19};
    int n = *(&arr + 1) - arr;
    cout << ceilVal(arr, 0, n - 1, 5);
    cout << endl;
}