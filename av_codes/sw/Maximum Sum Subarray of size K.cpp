using namespace std;
#define ll long long unsigned int
int main()
{
    //programming_lord
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
        long long sum=0;
        long long mx=0;
        while(j<size)
        {
            sum=sum+arr[j];
            if(j-i+1<k)
            {
                j++;
            }
            else if(j-i+1==k)
            {
                mx=max(mx,sum);
                sum=sum-arr[i];
                j++;
                i++;
                
            }
        }
        cout<<mx<<endl;
    
        
    }
return 0;
}
