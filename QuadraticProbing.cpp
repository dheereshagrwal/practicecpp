#include <iostream>
using namespace std;
#define SIZE 10
int hashF(int key)
{
    return key % SIZE;
}
int probe(int H[], int key)
{
    int index = hashF(key);
    int i = 0;
    while (H[(index + i * i) % SIZE] != 0)
        i++;
    return (index + i * i) % SIZE;
}
void Insert(int H[], int key)
{
    int index = hashF(key);
    if (H[index] != 0)
        index = probe(H, key);
    H[index] = key;
}
int Search(int H[], int key)
{
    int index = hashF(key);
    int i = 0;
    while (H[(index + i * i) % SIZE] != key)
        i++;
    return (index + i * i) % SIZE;
}
int main(void)
{
    int HT[SIZE] = {0};
    Insert(HT, 12);
    Insert(HT, 25);
    Insert(HT, 35);
    Insert(HT, 26);
    cout << "Key found at " << Search(HT, 35) << endl;
}