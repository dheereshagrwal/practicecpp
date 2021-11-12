#include <bits/stdc++.h>
using namespace std;
int maxSumSubArr(int A[], int n, int k)
{
    int sum = 0;
    int j = 0;
    int i = 0;
    int mx = INT_MIN;
    while (j < n)
    {
        sum = sum + A[j];
        if (j - i + 1 < k)
            j++;
        else if (j - i + 1 == k)
        {
            mx = max(sum, mx);
            sum = sum - A[i];
            i++;
            j++;
        }
    }
    return mx;
}