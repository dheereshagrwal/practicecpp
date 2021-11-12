#include <iostream>
using namespace std;

class Node
{
public:
    float data;
    Node *next;
    Node *prev;
};

class LinkedList
{
public:
    Node *Head;
    LinkedList() { Head = NULL; }
    LinkedList(float A[], int n);
    // ~LinkedList();
    int Display(Node *temp);
    bool Insert(Node *start, int loc, float data);
    float Delete(int index);
    void Reverse(Node *p);
    int Length(Node *start);
    int isCircular(Node *p);
};

int LinkedList::isCircular(Node *node)
{
    Node *p = node;
    Node *q = p; //**q is the fast pointer
    while (p != NULL && q != NULL && q->next != NULL)
    {
        p = p->next;
        q = q->next->next;
        if (p == q)
            return 1;
    }
    return 0;
}

//*Constructor

LinkedList::LinkedList(float A[], int n)
{
    Node *newNode, *temp;
    int i;

    // Iterate the loop until array length
    for (i = 0; i < n; i++)
    {
        // Create new node
        newNode = new Node;

        // Assign the array data
        newNode->data = A[i];

        // If it is first element
        // Put that node prev and next as start
        // as it is circular
        if (i == 0)
        {
            Head = newNode;
            newNode->prev = Head;
            newNode->next = Head;
        }
        else
        {
            // Find the last node
            temp = Head->prev;
            // cout << "Temp data is " << temp->data << endl;

            // Add the last node to make them
            // in circular fashion
            temp->next = newNode;
            newNode->next = Head;
            newNode->prev = temp;
            temp = Head;
            temp->prev = newNode;
        }
    }
}
//*Destructor

// LinkedList::~LinkedList()
// {
//     Node *p = Head;
//     while (Head != NULL)
//     {
//         Head = Head->next;
//         delete p;
//         p = Head;
//     }
// }
//**Display

int LinkedList::Display(Node *temp)
{
    Node *t = temp;
    if (temp == NULL)
        return 0;
    else
    {
        cout << "The list is: ";

        while (temp->next != t)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }

        cout << temp->data << endl;

        return 1;
    }
}
//*Length
int LinkedList::Length(Node *start)
{
    Node *p = start;
    int len = 1;
    while (p->next != start)
    {
        p = p->next;
        len++;
    }
    return len;
}

//*Insert

bool LinkedList::Insert(Node *start, int loc, float data) //**Index starting from 1 and index means after which index you want to insert
{
    Node *temp, *newNode;
    int i, count;

    // Create a new node in memory
    newNode = new Node;

    // Point temp to start
    temp = start;

    // count of total elements in the list
    count = Length(start);

    // If list is empty or the position is
    // not valid, return false
    if (temp == NULL || loc > count)
        return false;
    if (loc == 0)
    {
        Node *lastNode = temp->prev;
        newNode->data = data;
        newNode->next = temp;
        temp->prev = newNode;
        lastNode->next = newNode;
        newNode->prev = lastNode;
        Head = newNode;
        return true;
    }
    else
    {
        newNode->data = data;
        for (i = 0; i < loc - 1; i++)
        {
            temp = temp->next;
        }
        newNode->next = temp->next;
        (temp->next)->prev = newNode;
        temp->next = newNode;
        newNode->prev = temp;
        return true;
    }

    return false;
}

//*Delete

float LinkedList::Delete(int index)
{
    float x;
    if (index < 0 || index > Length(Head) - 1)
    {
        cout << "Index out of range: " << index << endl;
        return -1;
    }
    Node *p;
    if (index == 0)
    {
        p = Head;
        Node *lastNode = Head->prev;
        Head = Head->next;
        x = p->data;
        if (Head)
            lastNode->next = Head;
        delete p;
    }
    else
    {
        p = Head;
        for (int i = 0; i < index && p != NULL; i++)
        {
            p = p->next;
        }
        p->prev->next = p->next;
        if (p->next)
            p->next->prev = p->prev;
        x = p->data;
        // Head = p->next;
        delete p;
    }
    return x;
}

//*reverse
void LinkedList::Reverse(Node *p)
{
    p = Head;
    do
    {
        swap(p->next, p->prev);
        p = p->prev;
        cout << "p is at " << p->data << endl;
    } while (p != Head);
    Head = p->next;
}
int main(void)
{

    float A[] = {22, 4, 6, 8, 10};
    LinkedList l(A, 5);
    // cout << l.Delete(1) << endl;
    // cout << "%%%%%%%%%%%%%%%%" << endl;
    // l.Insert(l.Head, 2, 87);
    // cout << l.Length(l.Head);
    l.Reverse(l.Head);
    // cout << l.Delete(0) << endl;
    // cout << "&&&&&&&&&&&&&&&&&&&" << endl;
    l.Display(l.Head);
    // cout << l.isCircular(l.Head) << endl;
}