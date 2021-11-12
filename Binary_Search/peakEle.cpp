#include <bits/stdc++.h>
using namespace std;
int peakEle(int arr[], int start, int end)
{
    // int size = end + 1;
    // while (start <= end)
    // {
    //     int mid = start + (end - start) / 2;
    //     if (mid > 0 and mid < size - 1)
    //     {
    //         if (arr[mid] > arr[mid + 1] and arr[mid] > arr[mid - 1])
    //             return mid;
    //         else if (arr[mid - 1] > arr[mid])
    //             end = mid - 1;
    //         else
    //             start = mid + 1;
    //     }
    //     else if (mid == 0)
    //         return arr[0] > arr[1] ? 0 : 1;
    //     else if (mid == size - 1)
    //         return arr[size - 1] > arr[size - 2] ? size - 1 : size - 2;
    // }
    // return -1;

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
int main(void)
{
    int arr[] = {5, 20, 15, 10};
    int n = *(&arr + 1) - arr;
    cout << peakEle(arr, 0, n - 1);
    cout << endl;
}