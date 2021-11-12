#include <bits/stdc++.h>
using namespace std;
vector<int> maxSubArr(int A[], int n, int k)
{
    vector<int> ans;
    list<int> l;
    int i = 0;
    int j = 0;

    if (k > n) // edge case
    {
        ans.push_back(*max_element(l.begin(), l.end()));
        return ans;
    }

    while (j < n)
    {
        while (l.size() > 0 && l.back() < A[j])
            l.pop_back();
        l.push_back(A[j]);
        if ((j - i + 1) < k)
            j++;
        else if (j - i + 1 == k)
        {
            ans.push_back(l.front());
            if (l.front() == A[i])
                l.pop_front();
            i++;
            j++;
        }
    }
    return ans;
}
int main(void)
{
    int A[] = {2, 7, 5, 15, 14, 16, 18};
    vector<int> v;
    v = maxSubArr(A, 7, 3);
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << " ";
    cout << endl;
}