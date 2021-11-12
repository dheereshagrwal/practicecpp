#include <iostream>
#include <queue>
#include <stack>
#include <limits>
using namespace std;

class Heap
{
public:
    void Insert(float H[], int n);
    float Delete(float H[], int n);
};
void Heap::Insert(float H[], int n)
{
    float temp;
    int i = n;
    temp = H[i];
    while (i > 1 && temp > H[i / 2])
    {
        H[i] = H[i / 2];
        i = i / 2;
    }
    H[i] = temp;
}
float Heap::Delete(float H[], int n)
{
    int i, j;
    float val = H[1];
    float x = H[n];
    H[1] = H[n];
    H[n] = val;
    i = 1;
    j = 2 * i;
    while (j < n - 1)
    {
        if (H[j + 1] > H[j])
            j = j + 1;
        if (H[i] < H[j])
        {
            swap(H[i], H[j]);
            i = j;
            j = 2 * i;
        }
        else
            break;
    }
    return val;
}

int main(void)
{
    float H[] = {0, 10, 20, 30, 25, 5, 40, 35};
    Heap h;
    for (int i = 2; i < 8; i++)
        h.Insert(H, i);
    for (int i = 1; i < 8; i++)
        cout << H[i] << " ";
    cout << endl;
    for (int i = 7; i > 1; i--)
        h.Delete(H, i);
    cout << "Sorted array is " << endl;
    for (int i = 1; i < 8; i++)
        cout << H[i] << " ";
    cout << endl;
}