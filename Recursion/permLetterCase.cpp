#include <bits/stdc++.h>
using namespace std;

void permLetterCase(string ip, string op, vector<string> &v)
{
    if (ip.size() == 0)
    {
        v.push_back(op);
        return;
    }
    if (isalpha(ip[0]))
    {
        string op1 = op;
        string op2 = op;
        op1.push_back(tolower(ip[0]));
        op2.push_back(toupper(ip[0]));
        ip.erase(ip.begin() + 0);
        permLetterCase(ip, op1, v);
        permLetterCase(ip, op2, v);
    }
    else
    {
        string op1 = op;
        op1.push_back(ip[0]);
        ip.erase(ip.begin() + 0);
        permLetterCase(ip, op1, v);
    }
    return;
}
int main()
{
    string ip;
    cin >> ip;
    string op = "";
    vector<string> v;
    permLetterCase(ip, op, v);
    return 0;
}