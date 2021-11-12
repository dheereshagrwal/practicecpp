#include <iostream>
using namespace std;
void merge(int A[], int l, int mid, int h)
{
    int i, j, k;
    i = l;
    k = l;
    j = mid + 1;
    int B[h + 1];
    while (i <= mid && j <= h)
    {
        if (A[i] <= A[j])
            B[k++] = A[i++];
        else
            B[k++] = A[j++];
    }

    while (i <= mid)
        B[k++] = A[i++];
    while (j <= h)
        B[k++] = A[j++];
    for (i = l; i <= h; i++)
        A[i] = B[i];
}
void IMergeSort(int A[], int n)
{
    int p, l, h, mid, i;
    for (p = 2; p <= n; p = p * 2)
    {
        for (i = 0; i + p - 1 < n; i = i + p)
        {
            l = i;
            h = i + p - 1;
            mid = (l + h) / 2;
            merge(A, l, mid, h);
        }
    }
    if (p / 2 < n)
        merge(A, 0, p / 2 - 1, n - 1);
}
void RMergeSort(int A[], int l, int h)
{
    int mid;
    if (l < h)
    {
        mid = (l + h) / 2;
        RMergeSort(A, l, mid);
        RMergeSort(A, mid + 1, h);
        merge(A, l, mid, h);
    }
}
int main(void)
{
    int A[] = {11, 13, 7, 12, 16, 9, 24, 5, 10, 3};
    RMergeSort(A, 0, 9);
    for (int i = 0; i < 10; i++)
        cout << A[i] << " ";
    cout << endl;
}