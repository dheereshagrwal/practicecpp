#include <iostream>
#include <stack>
using namespace std;
void isBalance(string s)
{
    stack<char> a;
    int flag = 0;

    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '{' || s[i] == '[' || s[i] == '(')
        {
            a.push(s[i]);
            flag = 1;
        }
        if (!a.empty())
        {
            if (s[i] == '}')
            {
                if (a.top() == '{')
                {
                    a.pop();
                    continue;
                }
                else
                    break;
            }
            if (s[i] == ']')
            {
                if (a.top() == '[')
                {
                    a.pop();
                    continue;
                }
                else
                    break;
            }
            if (s[i] == ')')
            {
                if (a.top() == '(')
                {
                    a.pop();
                    continue;
                }
                else
                    break;
            }
        }
        else
            break;
    }

    if ((a.empty()) && (flag == 1))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}

int main(void)
{
    string expr = "(())";
    isBalance(expr);
    cout << endl;
}