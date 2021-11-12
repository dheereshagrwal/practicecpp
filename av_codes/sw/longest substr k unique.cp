#include<bits/stdc++.h>
using namespace std;
#define ll long long unsigned int
int main()
{
    //programming_lord
    int tc;
    cin>>tc;
    while(tc--)
    {
        string s;
        cin>>s;
        int k;
        cin>>k;
        unordered_map<char,int> mp;
        mp.clear();
        list<char> l;
        int i=0;
        int j=0;
        int mx=-1;
        
        while(j<s.length())
        {
            mp[s[j]]++;
            if(mp.size()<k)
            {
                j++;
            }
            else if(mp.size()==k)
            {
                mx=max(mx,j-i+1);
                j++;
            }
            else if(mp.size()>k)
            {
                while(mp.size()>k)
                {
                    mp[s[i]]--;
                    if(mp[s[i]]==0)
                    {
                        mp.erase(s[i]);
                    }
                    i++;
                }
                j++;
            }
        }
        cout<<mx<<endl;
    
        
    }
return 0;
}