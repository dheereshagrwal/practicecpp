#include<bits/stdc++.h>
using namespace std;
#define ll long long unsigned int
int main()
{
    int tc;
    cin>>tc;
    while(tc--)
    {
        int size,k;
        cin>>size>>k;
        int arr[size];
        for(int i=0;i<size;i++)
        {
            cin>>arr[i];
        }
        int i=0;
        int j=0;
        int mx=0;
        long long sum=0;

        while(j<size)
        {
            sum=sum+arr[j];
            if(sum<k)
            {
                j++;
            }
            else if(sum==k)
            {
                mx=max(mx,j-i+1);
                j++;
            }
            else if(sum>k)
            {
                while(sum>k)
                {
                    sum=sum-arr[i];
                    i++;
                }
                j++;
            }
        }
        cout<<mx<<endl;
    
        
    }
return 0;
}