#include <iostream>
using namespace std;
class Node
{
public:
    float data;
    Node *next;
} *first = NULL, *second = NULL, *third = NULL;

void createLL(float A[], int n)
{
    Node *t, *last;
    int i;
    first = new Node;
    first->data = A[0];
    first->next = NULL;
    last = first;
    for (i = 1; i < n; i++)
    {
        t = new Node;
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

void createLL2(float A[], int n)
{
    Node *t, *last;
    int i;
    second = new Node;
    second->data = A[0];
    second->next = NULL;
    last = second;
    for (i = 1; i < n; i++)
    {
        t = new Node;
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

int displayLL(Node *node)
{
    int count = 0;
    while (node != NULL)
    {
        count++;
        cout << node->data << endl;
        node = node->next;
    }
    return count;
}

float sumLL(Node *node)
{
    float sum = 0;
    while (node != NULL)
    {
        sum = sum + node->data;
        node = node->next;
    }
    return sum;
}

float maxLL(Node *node)
{
    float max = node->data;
    while (node != NULL)
    {
        if (node->data > max)
        {
            max = node->data;
        }
        node = node->next;
    }
    return max;

    //** Using Recursion

    // float MIN_FLOAT = -88898;
    // float x = 0;
    // if (node == NULL)
    //     return MIN_FLOAT;
    // else
    // {
    //     x = maxLL(node->next);
    //     return x > node->data ? x : node->data;
    // }
}

Node *searchLL(Node *node, float key)
{
    Node *q = NULL;
    while (node != NULL)
    {
        if (key == node->data)
        {
            q->next = node->next;
            node->next = first;
            first = node;
            return node;
        }
        q = node;
        node = node->next;
    }
    return NULL;
}

bool insertLL(Node *node, int index, float value) //**Index starting from 1 and index means after which index you want to insert
{
    Node *newNode = new Node;
    newNode->data = value;
    if (index < 0)
    {
        cout << "index should not be less than 0" << endl;
        return false;
    }
    else if (index == 0)
    {
        newNode->next = first;
        first = newNode;
        return true;
    }
    else
    {
        for (int i = 0; i < index - 1 && node != NULL; i++)
            node = node->next;
        if (node != NULL)
        {
            newNode->next = node->next;
            node->next = newNode;
        }
        return true;
    }
}
// void insertBeforeFirstNode(Node *node, float value)
// {
//     Node *newNode = new Node;
//     newNode->data = value;
//     newNode->next = first;
//     first = newNode;
// }

void insertAtLastNode(float value)
{
    Node *newNode = new Node;
    newNode->data = value;
    newNode->next = NULL;
    //check if the LL is empty or not
    if (first == NULL)
        first = newNode;
    else
    {
        Node *last = first;
        while (last->next != NULL)
            last = last->next;
        last->next = newNode;
    }
}

int findIndex(float value)
{
    int cnt = 0;
    Node *temp = first;
    while (temp != NULL && temp->data < value)
    {
        cnt++;
        temp = temp->next;
    }

    return cnt;
}
bool deleteNode(int index)
{
    if (index < 0)
    {
        cout << "Index should not be less than 0" << endl;
        return false;
    }
    else if (index == 0)
    {

        Node *p = first;
        float x = p->data;
        first = first->next;
        delete p;
        return true;
    }
    else
    {
        Node *q = NULL;
        Node *p = first;
        for (int i = 0; i < index && p != NULL; i++)
        {
            q = p;
            p = p->next;
        }
        q->next = p->next;
        delete p;
        return true;
    }
}

int checkSortLL(Node *node)
{
    Node *p = first;
    int flag = 0;
    while (p->next != NULL)
    {
        if (p->data <= p->next->data)
        {
            p = p->next;
            flag = 1;
        }
        else
        {
            flag = 0;
            break;
        }
    }
    return flag;
}

void deleteSortedDuplicatesLL(Node *node)
{
    Node *p = first;
    int cnt = 0;
    while (p->next != NULL && p != NULL)
    {
        if (p->data != p->next->data)
        {
            p = p->next;
            cnt++;
        }
        else
        {
            break;
        }
    }

    if (cnt >= 0)
        deleteNode(cnt);
}
void reverseLL(Node *node)
{
    Node *p = first;
    Node *q = NULL;
    Node *r = NULL;
    while (p != NULL)
    {
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }
    first = q;
}
void reverseLLRR(Node *q, Node *p)
{
    if (p != NULL)
    {
        reverseLLRR(p, p->next);
        p->next = q;
    }

    else
        first = q;
}
void concatenateLL(Node *p, Node *q)
{
    third = p;
    while (p->next != NULL)
        p = p->next;

    p->next = q;
    q = NULL;
}

void mergeLL(Node *p, Node *q)
{
    Node *last = NULL;
    if (p->data < q->data)
    {
        third = last = p;
        p = p->next;
        third->next = NULL;
    }
    else
    {
        third = last = q;
        q = q->next;
        third->next = NULL;
    }
    while (p != NULL && q != NULL)
    {
        if (p->data < q->data)
        {
            last->next = p;
            last = p;
            p = p->next;
            last->next = NULL;
        }
        else
        {
            last->next = q;
            last = q;
            q = q->next;
            last->next = NULL;
        }
    }
    if (p != NULL)
        last->next = p;
    if (q != NULL)
        last->next = q;
}

int isCircularLL(Node *node)
{
    Node *p = node;
    Node *q = node; //**q is the fast pointer
    while (p != NULL && q != NULL && q->next != NULL)
    {
        p = p->next;
        q = q->next->next;
        if (p == q)
            return 1;
    }
    return 0;
}
int main(void)
{

    float A[] = {2, 4, 6, 8, 10};
    createLL(A, 5);
    float B[] = {3, 5, 7};
    createLL2(B, 3);
    // float sm = sumLL(first);
    // float max = maxLL(first);
    // Node *temp;
    // temp = searchLL(first, 25); //**Uncomment if you want to search
    // if (temp)
    //     cout << "Key is found and data is " << temp->data << endl;
    // else
    //     cout << "Key is not found" << endl;

    // cout << "Sum of the elements is " << sm << endl;
    // cout << "Max of the elements is " << max << endl;
    // insertBeforeFirstNode(first, 69);
    // int cntBefore = displayLL(first);
    // cout << "Nodes before inserting and count are " << cntBefore << endl
    //      << endl
    //      << endl
    //      << endl;
    // insertAtLastNode(86);
    // insertAtLastNode(89);
    // insertAtLastNode(69);

    // if (insertLL(first, 0, 69))
    // {
    //     int cntAfter = displayLL(first);
    //     cout << "Nodes after inserting and count are " << cntAfter << endl;
    // }

    // int pos = findIndex(18);
    // cout << "Position is " << pos << endl;
    // insertLL(first, pos, 18);
    // int cntAfter = displayLL(first);
    // cout << "Nodes after inserting and count are " << cntAfter << endl;
    // int cntBefore = displayLL(first);
    // cout << "Nodes before inserting and count are " << cntBefore << endl;
    // cout << endl;

    // if (deleteNode(3))
    // {
    //     int cntAfter = displayLL(first);
    //     cout << "Nodes after deleting and count are " << cntAfter << endl;
    // }

    // int isSorted = checkSortLL(first);
    // cout << "Linked list is sorted " << isSorted << endl;

    // int cntBefore = displayLL(first);
    // cout << "Nodes before " << cntBefore << endl;
    // cout << endl;

    // deleteSortedDuplicatesLL(first);
    // int cntAfter = displayLL(first);
    // cout << "Nodes after deleting duplicates " << cntAfter << endl;

    // int cntBefore = displayLL(first);
    // cout << "Nodes before " << cntBefore << endl;
    // cout << endl;

    // reverseLLRR(NULL, first);
    // int cntAfter = displayLL(first);
    // cout << "Nodes after reversing and total " << cntAfter << endl;

    // displayLL(first);
    // cout << endl;
    // displayLL(second);

    // mergeLL(first, second);
    // displayLL(third);
    bool isCircular = isCircularLL(first);
    cout << "LL is circular: " << isCircular << endl;
}