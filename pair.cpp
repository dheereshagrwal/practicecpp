#include <iostream>
using namespace std;
int main(void)
{
    int k = 10;
    int i = 0;
    int j = 9;
    int A[10] = {1, 3, 4, 5, 6, 8, 9, 10, 12, 14};
    while (i < j)
    {
        if (A[i] + A[j] > k)
            j--;
        else if (A[i] + A[j] < k)
            i++;
        else
        {
            cout << A[i] << " matches with " << A[j] << endl;
            i++;
            j--;
        }
    }
}
