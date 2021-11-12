#include <bits/stdc++.h>
using namespace std;
void solveAllSubSeq(string ip, string op, vector<string> &v)
{
    if (ip.length() == 0)
    {
        v.push_back(op);
        return;
    }
    string op1 = op;
    string op2 = op;
    op2.push_back(ip[0]);
    ip.erase(ip.begin() + 0);
    solveAllSubSeq(ip, op1, v);
    solveAllSubSeq(ip, op2, v);

    return;
}

vector<string> powerSet(string s)
{
    string op = "";
    vector<string> v;
    solveAllSubSeq(s, op, v);
    return v;
}
int main()
{

    string s;
    cin >> s;
    vector<string> ans = powerSet(s);
    for (auto x : ans)
        cout << x << " ";
    cout << endl;

    return 0;
}
