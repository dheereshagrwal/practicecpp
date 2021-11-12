#include <bits/stdc++.h>
using namespace std;
int rain(int arr[], int n)
{
    int mxl[n];
    int mxr[n];
    int water[n];
    mxl[0] = arr[0];
    int i;
    int j;
    for (i = 1; i < n; i++)
        mxl[i] = max(mxl[i - 1], arr[i]);

    mxr[n - 1] = arr[n - 1];
    for (j = n - 2; j >= 0; j--)
        mxr[j] = max(mxr[j + 1], arr[j]);

    for (int k = 0; k < n; k++)
        water[k] = min(mxl[k], mxr[k]) - arr[k];

    for (int t = 0; t < n; t++)
        cout << mxr[t] << " ";
    cout << endl;

    return 0;
}
int main(void)
{
    int arr[] = {3, 0, 0, 2, 0, 4};
    rain(arr, 6);
}