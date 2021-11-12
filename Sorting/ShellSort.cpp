#include <bits/stdc++.h>
#include <iostream>
using namespace std;
void ShellSort(int A[], int n)
{
    int temp, gap, i, j;
    for (gap = n / 2; gap >= 1; gap = gap / 2)
    {
        for (i = gap; i < n; i++)
        {
            temp = A[i];
            j = i - gap;
            while (j >= 0 && A[j] > temp)
            {
                A[j + gap] = A[j];
                j = j - gap;
            }
            A[j + gap] = temp;
        }
    }
}
int main(void)
{
    int A[] = {11, 13, 7, 12, 16, 9, 24, 5, 10, 3};
    int n = *(&A + 1) - A;
    ShellSort(A, n);
    for (int i = 0; i < n; i++)
        cout << A[i] << " ";
    cout << endl;
}