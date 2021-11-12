#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void CountSort(int A[], int n)
{
    int l = *max_element(A, A + n);
    int C[l + 1];
    int k = 0;
    for (int i = 0; i < l + 1; i++)
        C[i] = 0;
    for (int i = 0; i < n; i++)
        C[A[i]]++;
    // for (int i = 0; i < l + 1; i++)
    //     for (int j = 0; j < C[i]; j++)
    //     {
    //         A[k] = i;
    //         k++;
    //     }

    int i = 0;
    int j = 0;
    while (j < l + 1)
    {
        if (C[j] > 0)
        {
            A[i++] = j;
            C[j]--;
        }
        else
            j++;
    }
}
int main(void)
{
    int A[] = {6, 3, 9, 10, 15, 6, 8, 12, 3, 6};
    CountSort(A, 10);
    for (int i = 0; i < 10; i++)
        cout << A[i] << " ";
    cout << endl;
}