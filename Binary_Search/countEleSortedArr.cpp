#include <bits/stdc++.h>
using namespace std;
int firstOcc(int arr[], int n, int ele)
{
    int start = 0;
    int end = n - 1;
    int res = -1;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (ele == arr[mid])
        {
            res = mid;
            end = mid - 1;
        }
        else if (ele < arr[mid])
            end = mid - 1;
        else
            start = mid + 1;
    }
    return res;
}
int lastOcc(int arr[], int n, int ele)
{
    int start = 0;
    int end = n - 1;
    int res = -1;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (ele == arr[mid])
        {
            res = mid;
            start = mid + 1;
        }
        else if (ele < arr[mid])
            end = mid - 1;
        else
            start = mid + 1;
    }
    return res;
}
int countEleSortedArr(int arr[], int n, int ele)
{
    return lastOcc(arr, n, ele) - firstOcc(arr, n, ele);
}