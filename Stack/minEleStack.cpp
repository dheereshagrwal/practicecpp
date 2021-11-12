#include <bits/stdc++.h>
using namespace std;
stack<int> s;
// stack<int> ss;
int minEle = INT_MAX;
// void push(int a)
// {
//     s.push(a);
//     if (ss.size() == 0 or s.top() >= a)
//         ss.push(a);
// }
// int pop()
// {
//     if (s.size() == 0)
//         return -1;
//     int ans = s.top();
//     s.pop();
//     if (ss.top() == ans)
//         ss.pop();
//     return ans;
// }
// int getmin()
// {
//     if (ss.size() == 0)
//         return -1;
//     return ss.top();
// }

void push(int x)
{
    if (s.size() == 0)
    {
        s.push(x);
        minEle = x;
    }
    else
    {
        if (x >= minEle)
            s.push(x);
        else if (x < minEle)
        {
            s.push(2 * x - minEle);
            minEle = x;
        }
    }
}
int pop()
{
    if (s.size() == 0)
        return -1;
    else
    {
        if (s.top() >= minEle)
            s.pop();
        else if (s.top() < minEle)
        {
            minEle = 2 * minEle - s.top();
            s.pop();
        }
    }
}
int top()
{
    if (s.size() == 0)
        return -1;
    else
    {
        if (s.top() >= minEle)
            return s.top();
        else if (s.top() < minEle)
            return minEle;
    }
}
int getmin()
{
    if (s.size() == 0)
        return -1;
    return minEle;
}