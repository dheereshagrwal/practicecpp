void print(int open,int close,string op,vector<string>& ans)
{
    if(open==0 && close==0)
    {
        ans.push_back(op);
        return;
    }
    if(open!=0)
    {
        string op1=op;
        op1.push_back('(');
        print(open-1,close,op1,ans);
    }
    if(close>open)
    {
        string op2=op;
        op2.push_back(')');
        print(open,close-1,op2,ans);
    }
    return;
}

//programming_lord

vector<string> Solution::generateParenthesis(int n) {
    int open=n;
    int close=n;
    string op="";
    vector<string> ans;
    print(open,close,op,ans);
    return ans;
}
