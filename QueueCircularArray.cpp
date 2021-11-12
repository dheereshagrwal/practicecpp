#include <iostream>
using namespace std;
class Queue
{
    int front = -1;
    int rear = -1;
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
    if (rear == size - 1)
        cout << "Queue is full!" << endl;
    else
    {
        rear = (rear + 1) % size;
        Q[rear] = value;
    }
}
void Queue::dequeue()
{
    if (front == rear)
        cout << "Queue is empty!" << endl;
    else
    {
        front = (front + 1) % size;
    }
}
void Queue::display()
{
    if (front == rear)
        cout << "Queue is empty!" << endl;
    else
    {
        int i = front + 1;
        do
        {
            cout << Q[i] << endl;
            i = (i + 1) % size;
        } while (i != (rear + 1) % size);
    }
}
int main(void)
{
    Queue q(5);
    q.enqueue(4);
    q.enqueue(5);
    q.enqueue(7);
    q.enqueue(9);
    q.enqueue(3);
    q.enqueue(35);

    // q.dequeue();
    q.display();
}