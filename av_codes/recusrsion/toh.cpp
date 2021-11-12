#include<bits/stdc++.h>
using namespace std;
#define ll long long unsigned int
void solve(int s,int h,int d,int n,int& count)
{
    count++;
    if(n==1)
    {
        cout<<"move disk "<<n<<" from rod "<<s<<" to rod "<<d<<endl;
        return;
    }
    solve(s,d,h,n-1,count);
    cout<<"move disk "<<n<<" from rod "<<s<<" to rod "<<d<<endl;
    solve(h,s,d,n-1,count);
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
        int a=1;
        int b=2;
        int c=3;
        int count=0;
        solve(a,b,c,n,count);
        cout<<count<<endl;

    
        
    }
return 0;
}