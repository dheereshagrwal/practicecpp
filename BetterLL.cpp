#include <iostream>
using namespace std;
template <class T>
class Node
{
public:
    T data;
    Node *next;
};

template <class T>
class LinkedList
{

public:
    Node<T> *first;
    LinkedList() { first = NULL; }
    LinkedList(T A[], int n);
    ~LinkedList();
    void Display();
    void Insert(int index, T value);
    T Delete(int index);
    int Length();
    void Middle(Node<T> *node);
};
//*Constructor
template <class T>
LinkedList<T>::LinkedList(T A[], int n)
{
    Node<T> *t, *last;
    int i;
    first = new Node<T>;
    first->data = A[0];
    first->next = NULL;
    last = first;
    for (i = 1; i < n; i++)
    {
        t = new Node<T>;
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}
//*Destructor
template <class T>
LinkedList<T>::~LinkedList()
{
    Node<T> *p = first;
    while (first != NULL)
    {
        first = first->next;
        delete p;
        p = first;
    }
}
template <class T>
void LinkedList<T>::Display()
{
    Node<T> *p = first;
    while (p != NULL)
    {
        cout << p->data << endl;
        p = p->next;
    }
}

template <class T>
int LinkedList<T>::Length()
{
    Node<T> *p = first;
    int len = 0;
    while (p != NULL)
    {
        len++;
        p = p->next;
    }
    return len;
}
template <class T>
void LinkedList<T>::Middle(Node<T> *node)
{
    Node<T> *p, *q;
    p = q = node;
    while (q)
    {
        q = q->next;
        if (q)
            q = q->next;
        if (q)
            p = p->next;
    }
    cout << "Middle is " << p->data << endl;
}

template <class T>
void LinkedList<T>::Insert(int index, T value) //**Index starting from 1 and index means after which index you want to insert
{
    Node<T> *t, *p = first;
    if (index < 0 || index > Length())
    {
        cout << "Index out of range: " << index << endl;
        return;
    }
    t = new Node<T>;
    t->data = value;
    t->next = NULL;

    if (index == 0)
    {
        t->next = first;
        first = t;
    }
    else
    {
        for (int i = 0; i < index - 1; i++)
            p = p->next;
        t->next = p->next;
        p->next = t;
    }
}
template <class T>
T LinkedList<T>::Delete(int index)
{
    Node<T> *p, *q = NULL;
    int x = -1;

    if (index < 0 || index > Length() - 1)
    {
        cout << "Index out of range: " << index << endl;
        return -1;
    }
    if (index == 0)
    {
        p = first;
        first = first->next;
        x = p->data;
        delete p;
    }
    else
    {
        p = first;
        for (int i = 0; i < index && p != NULL; i++)
        {
            q = p;
            p = p->next;
        }
        q->next = p->next;
        x = p->data;
        delete p;
    }
    return x;
}

int main(void)
{

    float A[] = {2, 4, 6, 8, 10};
    LinkedList<float> l(A, 5);
    // cout << l.Delete(1) << endl;
    // cout << "#######################" << endl;
    l.Middle(l.first);

    // l.Display();
}