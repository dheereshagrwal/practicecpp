#include <iostream>
using namespace std;
class Node
{
public:
    float data;
    Node *next;
};
class Stack
{
public:
    Node *top;
    Stack() { top = NULL; }
    ~Stack();
    void push(float value);
    void display();
    float pop();
    float peek(int indexFromTop);
    bool isEmpty();
    bool isFull();
    float stackTop();
};
Stack::~Stack()
{
    while (top != NULL)
    {
        Node *p = top;
        top = top->next;
        delete p;
    }
    delete top;
}
void Stack::push(float value)
{
    Node *t = new Node;
    if (t == NULL)
        cout << "Stack Overflow" << endl;
    else
    {
        t->data = value;
        t->next = top;
        top = t;
    }
}
float Stack::pop()
{
    float x = -1;
    if (top == NULL)
        cout << "Stack is Empty" << endl;
    else
    {
        Node *p = top;
        top = top->next;
        x = p->data;
        delete p;
    }
    return x;
}
float Stack::peek(int indexFromTop)
{
    Node *p = top;
    for (int i = 1; p != NULL && i < indexFromTop; i++)
        p = p->next;
    return p ? p->data : -1;
}
bool Stack::isEmpty()
{
    return top ? 0 : 1;
}
bool Stack::isFull()
{
    Node *t = new Node;
    bool r = t ? 1 : 0;
    delete t;
    return r;
}
float Stack::stackTop()
{
    return top ? top->data : -1;
}
void Stack::display()
{
    Node *p = top;
    while (p != NULL)
    {
        cout << p->data << endl;
        p = p->next;
    }
    cout << endl;
}
int main(void)
{
    Stack st;
    st.push(566);
    st.push(43);
    st.pop();
    st.display();
}