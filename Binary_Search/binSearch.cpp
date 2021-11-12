#include <bits/stdc++.h>
using namespace std;
int binSearch(int arr[], int n, int ele)
{
    int start = 0;
    int end = n - 1;
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
}