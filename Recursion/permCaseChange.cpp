#include <bits/stdc++.h>
using namespace std;

void permCaseChange(string ip, string op)
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
    op2.push_back(toupper(ip[0]));
    ip.erase(ip.begin() + 0);
    permCaseChange(ip, op2);
    permCaseChange(ip, op1);
    return;
}
int main()
{
    string ip;
    cin >> ip;
    string op = "";
    permCaseChange(ip, op);
    cout << endl;
    return 0;
}