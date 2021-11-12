#include<bits/stdc++.h>
using namespace std;
#define ll long long unsigned int
int main()
{
    int tc;
    cin>>tc;
    while(tc--)
    {
        int size;
        cin>>size;
        int arr[size];
        for(int i=0;i<size;i++)
        {
            cin>>arr[i];
        }
        int k;
        cin>>k;
        int i=0;
        int j=0;
        list<int> l;
        vector<int> v;

        while(j<size)
        {
            if(arr[j]<0)
            {
                l.push_back(arr[j]);
            }
            if(j-i+1<k)
            {
                j++;
            }
            else if(j-i+1==k)
            {
                if(l.size()==0)
                {
                    v.push_back(0);
                }
                else
                {
                    v.push_back(l.front());
                    if(arr[i]==l.front())
                    {
                        l.pop_front();
                    }
                }
                i++;
                j++;
            }
        }
        for(int i=0;i<v.size();i++)
        {
            cout<<v[i]<<" ";
        }
        cout<<endl;


    }
return 0;
}