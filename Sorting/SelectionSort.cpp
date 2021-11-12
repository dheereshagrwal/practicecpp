#include <iostream>
using namespace std;
void SelectionSort(float A[], int n)
{
    int i, j, k = 0;
    j = 1;
    for (i = 0; i < n - 1; i++)
    {
        for (j = k = i; j < n; j++)
            if (A[j] < A[k])
                k = j;
        swap(A[i], A[k]);
    }
}
int main(void)
{
    float A[] = {8, 5, 7, 3, 2};
    SelectionSort(A, 5);
    for (int i = 0; i < 5; i++)
        cout << A[i] << " ";
    cout << endl;
}