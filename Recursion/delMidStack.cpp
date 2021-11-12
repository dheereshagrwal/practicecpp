#include <bits/stdc++.h>
using namespace std;
void solve(stack<int> &st, int k)
{
    if (k == 1)
    {
        st.pop();
        return;
    }
    int temp = st.top();
    st.pop();
    solve(st, k - 1);
    st.push(temp);
}
stack<int> delMid(stack<int> st, int size)
{
    if (st.size() == 0)
        return st;
    int k = size / 2 + 1;
    solve(st, k);
    return st;
}