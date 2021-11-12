#include <bits/stdc++.h>
using namespace std;
#define ll long long unsigned int
void print(int n)
{
    if (n == 1)
    {
        cout << n << " ";
        return;
    }
    cout << n << " ";
    print(n - 1);
}
int main()
{
    //programming_lord
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n;
        cin >> n;
        print(n);
        cout << endl;
    }
    return 0;
}