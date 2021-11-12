#include <bits/stdc++.h>
using namespace std;
bool isValid(int arr[], int n, int k, int mx)
{
    int sum = 0;
    int nStudents = 1;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > mx)
            return false;
        sum = sum + arr[i];
        if (sum > mx)
        {
            nStudents++;
            sum = arr[i];
        }
        if (nStudents > k)
            return false;
    }

    return true;
}
int minPages(int arr[], int start, int end, int n, int k)
{
    if (n < k)
        return -1;
    int res = -1;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (isValid(arr, n, k, mid))
        {
            res = mid;
            end = mid - 1;
        }
        else
            start = mid + 1;
    }
    return res;
}
int main(void)
{
    int arr[] = {12, 34, 67, 90};
    int n = *(&arr + 1) - arr;
    int mx = *max_element(arr, arr + n);
    int sm = accumulate(arr, arr + n, 0);
    cout << minPages(arr, mx, sm, n, 2);
}