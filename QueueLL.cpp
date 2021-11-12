#include <iostream>
using namespace std;
class Node
{
public:
    float data;
    Node *next;
};

class Queue
{
public:
    Node *front;
    Node *rear;
    Queue();
    ~Queue();
    void enqueue(float value);
    void dequeue();
    void display();
};

Queue::Queue()
{
    front = NULL;
    rear = NULL;
}
Queue::~Queue()
{
    while (front != NULL)
    {
        Node *p = front;
        front = front->next;
        delete p;
    }
    delete front;
}
void Queue::enqueue(float value)
{
    Node *t = new Node;
    if (t == NULL)
        cout << "Queue overflow" << endl;
    else
    {
        t->data = value;
        t->next = NULL;
        if (front == NULL)
            front = rear = t;
        else
        {
            rear->next = t;
            rear = t;
        }
    }
}
void Queue::dequeue()
{
    if (front == NULL)
        cout << "Queue underflow" << endl;
    else
    {
        Node *p = front;
        front = front->next;
        delete p;
    }
}
void Queue::display()
{
    if (front == NULL)
        cout << "Queue underflow" << endl;
    else
    {
        Node *p = front;
        while (p != NULL)
        {
            cout << p->data << endl;
            p = p->next;
        }
    }
}
int main(void)
{
    Queue q;
    q.enqueue(15);
    q.enqueue(35);
    q.enqueue(37);
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.display();
}