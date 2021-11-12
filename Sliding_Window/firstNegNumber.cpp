#include <bits/stdc++.h>
using namespace std;
vector<int> firstNegNumber(int A[], int n, int k)
{
    int j = 0;
    int i = 0;
    list<int> l;
    vector<int> v;
    while (j < n)
    {
        if (A[j] < 0)
            l.push_back(A[j]);
        if (j - i + 1 < k)
            j++;
        else if (j - i + 1 == k)
        {
            if (l.size() == 0)
                v.push_back(0);
            else
                v.push_back(l.front());
            if (A[i] < 0)
                l.pop_front();
            i++;
            j++;
        }
    }
    return v;
}
int main(void)
{
    int A[] = {-12, -7, 8, -15, 30, 16, 28};
    vector<int> v;
    v = firstNegNumber(A, 7, 3);
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << " ";
    cout << endl;
}