#include<bits/stdc++.h>
using namespace std;
#define ll long long unsigned int
void push(vector<int>& v,int temp)
{
    if(v.size()==0 || v[v.size()-1]<=temp)
    {
        v.push_back(temp);
        return;
    }
    int val=v[v.size()-1];
    v.pop_back();
    push(v,temp);
    v.push_back(val);
    return;
}
void sort(vector<int>& v)
{
    if(v.size()==1)
    {
        return;
    }
    int temp=v[v.size()-1];
    v.pop_back();
    sort(v);
    push(v,temp);
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
        vector<int> v;
        for(int i=0;i<size;i++)
        {
            int a;
            cin>>a;
            v.push_back(a);
        }
        sort(v);
        
        for(int i=0;i<v.size();i++)
        {
            cout<<v[i]<<" ";
        }
        cout<<endl;
    
        
    }
return 0;
}