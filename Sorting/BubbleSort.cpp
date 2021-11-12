#include <iostream>
using namespace std;

void BubbleSort(float A[], int n)
{
    int flag;
    for (int i = 0; i < n - 1; i++)
    {
        flag = 0;
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (A[j] > A[j + 1])
                swap(A[j], A[j + 1]);
            flag = 1;
        }
        if (flag == 0)
            break;
    }
}
int main(void)
{
    float A[] = {8, 5, 7, 3, 2};
    BubbleSort(A, 5);
    for (int i = 0; i < 5; i++)
        cout << A[i] << " ";
    cout << endl;
}