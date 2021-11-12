#include <iostream>
#include <stack>
#include <cstring>
using namespace std;
int isOperand(char x)
{
    if (x == '+' || x == '-' || x == '/' || x == '*')
        return 0;
    else
        return 1;
}
int pre(char x)
{
    if (x == '+' || x == '-')
        return 1;
    else if (x == '*' || x == '/')
        return 2;
    return 0;
}
stack<char> st;
char *convert(const char *infix)
{
    // stack<char> st;
    char *postfix = new char[strlen(infix) + 2];
    int i = 0, j = 0;
    while (infix[i] != '\0')
    {
        if (isOperand(infix[i]))
            postfix[j++] = infix[i++];
        else
        {
            if (pre(infix[i]) > pre(st.top()))
                st.push(infix[i++]);
            else
            {
                postfix[j++] = st.top();
                st.pop();
            }
        }
    }
    while (!st.empty())
    {
        postfix[j++] = st.top();
        st.pop();
    }
    postfix[j - 1] = '\0';
    return postfix;
}

float eval(char *postfix)
{
    stack<float> evalSt;
    int i;
    float operand;
    float value1;
    float value2;
    float result;
    for (i = 0; postfix[i] != '\0'; i++)
    {
        if (isOperand(postfix[i]))
        {
            float operand = postfix[i] - '0';
            evalSt.push(operand);
        }

        else if (!evalSt.empty())
        {
            value2 = evalSt.top();
            evalSt.pop();
            value1 = evalSt.top();
            evalSt.pop();
            switch (postfix[i])
            {
            case '+':
                result = value1 + value2;
                evalSt.push(result);
                break;
            case '-':
                result = value1 - value2;
                evalSt.push(result);
                break;
            case '*':
                result = value1 * value2;
                evalSt.push(result);
                break;
            case '/':
                result = value1 / value2;
                evalSt.push(result);
                break;
            default:
                break;
            }
        }
    }
    return evalSt.top();
}
int main(void)
{
    char const *infix = "3*5+6/2-4";
    st.push(' ');
    char *postfix = convert(infix);
    cout << postfix << endl;
    cout << eval(postfix) << endl;
}