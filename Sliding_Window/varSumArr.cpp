#include <bits/stdc++.h>
using namespace std;
int varSumArr(int A[], int n, int k)
{
    int sum = 0;
    int j = 0;
    int i = 0;
    int mx = 0;
    while (j < n)
    {
        sum = sum + A[j];
        if (sum < k)
            j++;
        else if (sum == k)
        {
            mx = max(mx, j - i + 1);
            j++;
        }
        else if (sum > k)
        {
            while (sum > k)
            {
                sum = sum - A[i];
                i++;
            }
            j++;
        }
    }
    return mx;
}