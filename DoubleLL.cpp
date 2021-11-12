#include <iostream>
using namespace std;
template <class T>
class Node
{
public:
    T data;
    Node *next;
    Node *prev;
};

template <class T>
class LinkedList
{
public:
    Node<T> *first;
    LinkedList() { first = NULL; }
    LinkedList(T A[], int n);
    // ~LinkedList();
    void Display();
    void Insert(int index, T value);
    T Delete(int index);
    void Reverse(Node<T> *p);
    int Length();
};
//*Constructor
template <class T>
LinkedList<T>::LinkedList(T A[], int n)
{
    Node<T> *t, *last;
    int i;
    first = new Node<T>;
    first->data = A[0];
    first->prev = first->next = NULL;
    last = first;
    for (i = 1; i < n; i++)
    {
        t = new Node<T>;
        t->data = A[i];
        t->next = NULL;
        t->prev = last;
        last->next = t;
        last = t;
    }
}
//*Destructor
// template <class T>
// LinkedList<T>::~LinkedList()
// {
//     Node<T> *p = first;
//     while (first != NULL)
//     {
//         first = first->next;
//         delete p;
//         p = first;
//     }
// }
//**Display
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
//*Length
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

//*Insert
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
    t->prev = NULL;

    if (index == 0)
    {
        t->next = first;
        first->prev = t;
        first = t;
    }
    else
    {
        for (int i = 0; i < index - 1; i++)
            p = p->next;
        t->next = p->next;
        t->prev = p;
        if (p->next != NULL)
            p->next->prev = t;
        p->next = t;
    }
}

//*Delete
template <class T>
T LinkedList<T>::Delete(int index)
{
    Node<T> *p = NULL;
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
        if (first)
            first->prev = NULL;
    }
    else
    {
        p = first;
        for (int i = 0; i < index && p != NULL; i++)
        {
            p = p->next;
        }
        p->prev->next = p->next;
        if (p->next)
            p->next->prev = p->prev;
        x = p->data;
        delete p;
    }
    return x;
}
template <class T>
void LinkedList<T>::Reverse(Node<T> *p)
{
    p = first;
    Node<T> *temp;
    while (p)
    {
        cout << "p->next is " << p->next->data << endl;
        swap(p->next, p->prev);
        cout << "p->prev is " << p->prev->data << endl;

        p = p->prev;
        cout << "Now p is " << p->data << endl;
        cout << "########" << endl;
        if (p != NULL && p->next == NULL)
            first = p;
    }
}
int main(void)
{

    float A[] = {2, 4, 6, 8, 10};
    LinkedList<float> l(A, 5);
    // cout << l.Delete(1) << endl;
    // cout << "%%%%%%%%%%%%%%%%" << endl;
    // l.Insert(1, 87);
    // l.Reverse(l.first);
    l.Display();
}