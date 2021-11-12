#include <bits/stdc++.h>
using namespace std;
void push(stack<int> &s, int temp)
{
    if (s.size() == 0 or s.top() <= temp)
    {
        s.push(temp); // push of the stack
        return;
    }
    int val = s.top();
    s.pop();
    push(s, temp);
    s.push(val);
    return;
}
void sort(stack<int> &s)
{
    if (s.size() == 1)
        return;
    int temp = s.top();
    s.pop();
    sort(s);
    push(s, temp);
    return;
}
int main()
{
    stack<int> s;
    s.push(9);
    s.push(10);
    s.push(2);
    s.push(5);
    sort(s);

    cout << s.top() << endl;
    s.pop();
    cout << s.top() << endl;
    s.pop();
    cout << s.top() << endl;
    s.pop();
    cout << s.top() << endl;
    s.pop();

    cout << endl;
    return 0;
}