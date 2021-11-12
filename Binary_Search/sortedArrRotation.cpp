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
int minIndex(int arr[], int n)
{
    int start = 0;
    int end = n - 1;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        int next = (mid + 1) % n;
        int prev = (mid - 1 + n) % n;

        if (arr[mid] <= arr[next] && arr[mid] <= arr[prev])
            return mid;
        if (arr[start] <= arr[mid])
            start = mid + 1;
        else if (arr[mid] <= arr[end])
            end = mid - 1;
    }
    return -1;
}
int findEle(int arr[], int n, int ele)
{
    return max(binSearch(arr, 0, minIndex(arr, n) - 1, ele), binSearch(arr, minIndex(arr, n), n - 1, ele));
}
int main(void)
{
    int arr[] = {15, 18, 2, 3, 6, 12};
    int n = *(&arr + 1) - arr;
    cout << findEle(arr, n, 6);
}