#include <iostream>
using namespace std;

void InsertionSort(float A[], int n)
{
    float x;
    int j;
    for (int i = 1; i < n; i++)
    {
        x = A[i];
        j = i - 1;
        while (A[j] > x && j > -1)
        {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = x;
    }
}
int main(void)
{
    float A[] = {8, 5, 7, 3, 2};
    InsertionSort(A, 5);
    for (int i = 0; i < 5; i++)
        cout << A[i] << " ";
    cout << endl;
}