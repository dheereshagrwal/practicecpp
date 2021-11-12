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
    Node<T> *Head;
    LinkedList() { Head = NULL; }
    LinkedList(T A[], int n);
    void Display();
    void RDisplay(Node<T> *h);
    void Insert(int index, T value);
    T Delete(int index);
    int Length();
};

//*Constructor
template <class T>
LinkedList<T>::LinkedList(T A[], int n)
{
    Node<T> *t, *last;
    int i;
    Head = new Node<T>;
    Head->data = A[0];
    Head->next = Head;
    last = Head;
    for (i = 1; i < n; i++)
    {
        t = new Node<T>;
        t->data = A[i];
        t->next = last->next;
        last->next = t;
        last = t;
    }
}

template <class T>
void LinkedList<T>::Display()
{
    Node<T> *p = Head;
    do
    {
        cout << p->data << endl;
        p = p->next;
    } while (p != Head);
    cout << endl;
}
template <class T>
void LinkedList<T>::RDisplay(Node<T> *h)
{
    static int flag = 0;
    if (h != Head or flag == 0)
    {
        flag = 1;
        cout << h->data << endl;
        RDisplay(h->next);
    }
    flag = 0;
}
template <class T>
int LinkedList<T>::Length()
{
    Node<T> *p = Head;
    int len = 0;
    do
    {
        len++;
        p = p->next;
    } while (p != Head);
    return len;
}
//**Insertion
template <class T>
void LinkedList<T>::Insert(int index, T value) //**Index starting from 1 and index means after which index you want to insert
{
    Node<T> *t, *p = Head;
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
        Node<T> *tail = Head;
        while (tail->next != Head)
            tail = tail->next;
        t->next = Head;
        Head = t;
        tail->next = Head;
    }
    else
    {
        for (int i = 0; i < index - 1; i++)
            p = p->next;
        t->next = p->next;
        p->next = t;
    }
}
//*Deletion
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
        Node<T> *tail = Head;
        while (tail->next != Head)
            tail = tail->next;
        p = Head;
        Head = Head->next;
        tail->next = Head;
        x = p->data;
        delete p;
    }
    else
    {
        p = Head;
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
    l.Delete(5);
    cout << endl;
    l.RDisplay(l.Head);
}