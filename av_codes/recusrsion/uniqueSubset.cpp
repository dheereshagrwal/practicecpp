#include<bits/stdc++.h>
using namespace std;
#define ll long long unsigned int
void solve(vector<int> ip,vector<int> op,set<vector<int>>& mp)
{
    if(ip.size()==0)
    {
            sort(op.begin(),op.end());
            mp.insert(op);
        return;
    }
    vector<int> op1=op;
    vector<int> op2=op;
    op2.push_back(ip[0]);
    ip.erase(ip.begin()+0);
    solve(ip,op1,mp);
    solve(ip,op2,mp);
    return;
    
}
int main()
{
    //programming_lord
    int tc;
    cin>>tc;
    while(tc--)
    {
        int size;
        cin>>size;
        vector<int> ip;
        for(int i=0;i<size;i++)
        {
            int a;
            cin>>a;
            ip.push_back(a);
        }
        vector<int> op;
        op.clear();
        set<vector<int>> mp;
        mp.clear();
        solve(ip,op,mp);
        if(mp.size()==0)
        {
            cout<<"Empty";
        }
        else
        for(auto it=mp.begin();it!=mp.end();it++)
        {
            vector<int> v=*it;
            cout<<'(';
            bool first=true;
            for(int i=0;i<v.size();i++)
            {
                if(first==true)
                {
                    cout<<v[i];
                    first=false;
                }
                else
                {
                    cout<<" "<<v[i];
                }
            }
            cout<<')';
            
        }
        cout<<endl;
        
    }
return 0;
}