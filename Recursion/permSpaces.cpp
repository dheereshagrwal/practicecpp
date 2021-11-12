#include <bits/stdc++.h>
using namespace std;

void permSpaces(string ip, string op)
{
    if (ip.size() == 0)
    {
        cout << '(';
        cout << op;
        cout << ')';
        return;
    }
    string op1 = op;
    string op2 = op;
    op1.push_back(ip[0]);
    op2.push_back(' ');
    op2.push_back(ip[0]);

    ip.erase(ip.begin() + 0);
    permSpaces(ip, op2);
    permSpaces(ip, op1);
    return;
}
int main()
{
    string ip;
    cin >> ip;
    string op = "";
    op.push_back(ip[0]);
    ip.erase(ip.begin() + 0);
    permSpaces(ip, op);
    cout << endl;

    return 0;
}