#include<bits/stdc++.h>
using namespace std;
#define ll long long unsigned int
void print(int one,int zero,int n,string op)
{
    if(n==0)
    {
        cout<<op<<" ";
        return;
    }
    string op1=op;
    op1.push_back('1');
    print(one+1,zero,n-1,op1);
    if(one>zero)
    {
        string op2=op;
        op2.push_back('0');
        print(one,zero+1,n-1,op2);
    }
    return;
}
int main()
{
    //programming_lord
    int tc;
    cin>>tc;
    while(tc--)
    {
        int n;
        cin>>n;
        string op="";
        int one=0;
        int zero=0;
        print(one,zero,n,op);
        cout<<endl;
    
        
    }
return 0;
}