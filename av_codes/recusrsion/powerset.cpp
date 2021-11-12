// { Driver Code Starts
//Initial Template for C++


// CPP program to generate power set
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


//User function Template for C++

//Complete this function
void solve(string ip, string op,vector<string>& v)
{
    if(ip.length()==0)
    {
        v.push_back(op);
        return;
    }
    
    string op1 = op;
    string op2 = op;
    op2.push_back(ip[0]);
    ip.erase(ip.begin()+0);
    solve(ip,op1,v);
    solve(ip,op2,v);
    
    return;
    
}
vector <string> powerSet(string s)
{
    string op="";
    vector<string> v;
    solve(s,op,v);
    sort(v.begin(),v.end());

    return v;
}


// { Driver Code Starts.


// Driver code
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        string s;
        cin>>s;
        vector<string> ans = powerSet(s);
        sort(ans.begin(),ans.end());
        for(auto x:ans)
        cout<<x<<" ";
        cout<<endl;
        
        
    }

return 0;
}   // } Driver Code Ends