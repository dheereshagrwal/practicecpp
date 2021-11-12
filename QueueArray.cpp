#include <iostream>
using namespace std;
class Queue
{
    int front = 0;
    int rear = 0;
    int size;
    float *Q;

public:
    Queue(int size);
    ~Queue();
    void enqueue(float value);
    void dequeue();
    bool isEmpty();
    bool isFull();
    void display();
};

Queue::Queue(int size)
{
    this->size = size;
    Q = new float[this->size];
}
Queue::~Queue()
{
    delete Q;
}
void Queue::enqueue(float value)
{
    if ((rear + 1) % size == size - 1)
        cout << "Queue is full!" << endl;
    else
    {
        rear++;
        Q[rear] = value;
    }
}
void Queue::dequeue()
{
    if (front == rear)
        cout << "Queue is empty!" << endl;
    else
    {
        front++;
    }
}
void Queue::display()
{
    if (front == rear)
        cout << "Queue is empty!" << endl;
    else
        for (int i = front + 1; i <= rear; i++)
            cout << Q[i] << endl;
}
int main(void)
{
    Queue q(5);
    q.enqueue(4);
    q.enqueue(5);
    q.enqueue(7);
    q.enqueue(9);
    q.enqueue(3);
    q.dequeue();
    q.display();
}