#include<bits/stdc++.h>
using namespace std;
#define ll long long unsigned int
void print(vector<int> ip,int indx,int k,int& ans)
{
    if(ip.size()==1)
    {
        ans=ip[0];
        return;
    }
    indx=(indx+k)%ip.size();
    ip.erase(ip.begin()+indx);
    print(ip,indx,k,ans);
    return;
}
int main()
{
    int tc;
    cin>>tc;
    while(tc--)
    {
        int n,k;
        cin>>n>>k;
    vector<int> ip;
    for(int i=1;i<=n;i++)
    {
        ip.push_back(i);
    }
    int ans;
    k--;
    int indx=0;
    print(ip,indx,k,ans);
    cout<<ans<<endl;
        
    }
return 0;
}