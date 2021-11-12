#include <bits/stdc++.h>
using namespace std;
int firstOcc(int arr[], int start, int end, int ele)
{
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
int findEle(int arr[], int n, int ele)
{
    int start = 0;
    int end = 1;
    if (arr[end] == ele)
        return end;
    if (arr[start] == ele)
        return start;
    while (arr[end] < ele)
    {
        start = end;
        end = end * 2;
    }
    return firstOcc(arr, start, end, ele);
}
