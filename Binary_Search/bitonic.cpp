#include <bits/stdc++.h>
using namespace std;
int binSearch(int arr[], int start, int end, int ele)
{
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (ele == arr[mid])
            return mid;
        else if (ele < arr[mid])
            end = mid - 1;
        else
            start = mid + 1;
    }
    return -1;
}
int revBinSearch(int arr[], int start, int end, int ele)
{
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (ele == arr[mid])
            return mid;
        else if (ele < arr[mid])
            start = mid + 1;
        else
            end = mid - 1;
    }
    return -1;
}

int peakEle(int arr[], int start, int end)
{

    while (start < end)
    {
        int mid = start + (end - start) / 2;
        if (arr[mid] > arr[mid + 1])
            end = mid;
        else
            start = mid + 1;
    }
    return start;
}
int revPeakEle(int arr[], int start, int end)
{
    while (start < end)
    {
        int mid = start + (end - start) / 2;
        if (arr[mid] < arr[mid + 1])
            end = mid;
        else
            start = mid + 1;
    }
    return start;
}
int maxEle(int arr[], int start, int end)
{
    return peakEle(arr, start, end);
}

int findEle(int arr[], int start, int end, int ele)
{
    int idx = peakEle(arr, start, end);
    int peakEle = arr[idx];
    int left = binSearch(arr, 0, idx - 1, ele);
    int right = revBinSearch(arr, idx, end, ele);
    return left >= right ? left : right;
}
int main(void)
{
    int arr[] = {1, 3, 8, 12, 4, 2};
    int n = *(&arr + 1) - arr;
    cout << findEle(arr, 0, n - 1, 4);
    cout << endl;
}