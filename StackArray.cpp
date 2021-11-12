#include <iostream>
using namespace std;
class Stack
{

    int size;
    int top;
    float *S;

public:
    Stack();
    Stack(int size);
    ~Stack();
    void push(float value);
    void display();
    float pop();
    float peek(int indexFromTop);
    bool isEmpty();
    bool isFull();
    float stackTop();
};
Stack::Stack(int size)
{
    top = -1;
    this->size = size;
    S = new float[this->size];
}
Stack::~Stack()
{
    delete[] S;
}
void Stack::display()
{
    if (top == 1)
        cout << "Stack is empty!" << endl;
    else
    {
        for (int i = top; i >= 0; i--)
            cout << S[i] << endl;
    }
    cout << endl;
}
void Stack::push(float value)
{
    if (top == (size)-1)
        cout << "Stack Overflow" << endl;
    else
    {
        top++;
        S[top] = value;
    }
}
float Stack::pop()
{
    float x = -1;
    if (top == -1)
        cout << "Stack Underflow" << endl;
    else
        x = S[top--];
    return x;
}
float Stack::peek(int indexFromTop)
{
    float x = -1;
    if ((top - indexFromTop + 1) < 0 || indexFromTop > size)
        cout << "Invalid index" << endl;
    else
        x = S[top - indexFromTop + 1];

    return x;
}
bool Stack::isEmpty()
{
    return (top == -1) ? true : false;
}
bool Stack::isFull()
{
    return (top == size - 1) ? true : false;
}

float Stack::stackTop()
{
    return isEmpty() ? -1 : S[top];
}
int main(void)
{
    Stack st(4);
    // st.push(78);
    // st.push(79);
    // st.push(69);
    // st.push(59);

    // cout << "Value " << st.pop() << " is popped" << endl;
    st.display();
    // cout << "After peeking " << st.peek(5) << endl;

    cout << st.stackTop() << endl;
}