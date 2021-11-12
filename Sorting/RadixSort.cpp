// implementation of radix sort using bin/bucket sort
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
} *first = NULL;
Node *Create(int value)
{
    Node *temp = new Node();
    temp->data = value;
    temp->next = NULL;
    return temp;
}
void Insert(Node *&first, int value)
{
    if (first == NULL)
    {
        first = Create(value);
        return;
    }
    Node *t = first;
    while (t->next != NULL)
        t = t->next;
    t->next = Create(value);
}
int Delete(Node *&first)
{
    if (first == NULL)
        return 0;
    Node *p = first;
    int value = first->data;
    first = first->next;
    delete p;
    return value;
}

int Digits(int n)
{
    int i = 1;
    if (n < 10)
        return 1;
    while (n > (int)pow(10, i))
        i++;
    return i;
}

// void RadixSort(vector<int> &A)
void RadixSort(int A[], int n)

{

    // int n = A.size();

    // int max_val = *max_element(A.begin(), A.end());
    int max_val = *max_element(A, A + n);
    int n_digits = Digits(max_val);

    Node **Bins;

    Bins = new Node *[10];
    for (int i = 0; i < 10; i++)
        Bins[i] = NULL;
    for (int i = 0; i < n_digits; i++)
    {
        for (int j = 0; j < n; j++)
            Insert(Bins[(A[j] / (int)pow(10, i)) % 10], A[j]);

        int x = 0, y = 0;

        while (x < 10)
        {
            while (Bins[x] != NULL)
                A[y++] = Delete(Bins[x]);
            x++;
        }
    }
}

int main()
{
    // vector<int> A = {573, 25, 415, 12, 161, 6};
    int A[] = {573, 25, 415, 12, 161, 6};

    int n = *(&A + 1) - A;
    RadixSort(A, n);
    for (int i = 0; i < n; i++)
        cout << A[i] << " ";
    cout << endl;

    return 0;
}
