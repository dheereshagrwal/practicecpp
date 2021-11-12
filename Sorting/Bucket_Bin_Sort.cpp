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

// void Bucket_Bin_Sort(vector<int> &A)
void Bucket_Bin_Sort(int A[], int n)
{
    // int n = A.size();
    // int max_val = *max_element(A.begin(), A.end());
    int max_val = *max_element(A, A + n);
    Node **Bins;
    Bins = new Node *[max_val + 1];
    for (int i = 0; i < max_val + 1; i++)
        Bins[i] = NULL;
    for (int i = 0; i < n; i++)
        Insert(Bins[A[i]], A[i]);

    int i = 0;
    int j = 0;
    while (i < max_val + 1)
    {
        while (Bins[i])
            A[j++] = Delete(Bins[i]);
        i++;
    }
}

int main()
{
    // vector<int> A = {6, 8, 3, 10, 15, 6, 9, 12, 6, 3};
    int A[] = {6, 8, 3, 10, 15, 6, 9, 12, 6, 3};
    int n = *(&A + 1) - A;
    Bucket_Bin_Sort(A, n);
    for (int i = 0; i < n; i++)
        cout << A[i] << " ";
    cout << endl;
    return 0;
}