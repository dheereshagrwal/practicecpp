#include <bits/stdc++.h>
using namespace std;
int binSearchNearlySortedArr(int arr[], int start, int end, int ele, int k)
{
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (ele == arr[mid])
            return mid;
        if (mid - k >= start and ele == arr[mid - k])
            return mid - k;
        if (mid + k <= end and ele == arr[mid + k])
            return mid + k;
        else if (ele < arr[mid] or (ele < arr[mid + k] and mid + k <= end) or (ele < arr[mid - k] and mid - k >= start))
            end = mid - k - 1;
        else
            start = mid + k + 1;
    }
    return -1;
}
int main(void)
{
    int arr[] = {10, 3, 40, 20, 50, 80, 70};
    int n = *(&arr + 1) - arr;
    int k = 1;
    cout << binSearchNearlySortedArr(arr, 0, n - 1, 90, k);
}