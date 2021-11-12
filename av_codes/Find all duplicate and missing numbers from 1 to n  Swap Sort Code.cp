#include<bits/stdc++.h>
using namespace std;

int main() {
    int size;
    cin>>size;
    
    int arr[size];
    for(int i=0;i<size;i++)
    {
        cin>>arr[i];
    }

    int i=0;
    while(i<size)
    {
        if(arr[i]!=arr[arr[i]-1])
        {
            swap(arr[i],arr[arr[i]-1]);
        }
        else
        {
            i++;
        }
    }
    
    
    for(int i=0;i<size;i++)
    {
        if(arr[i]!=i+1)
        {
            cout<<"Missing is: "<<i+1<<endl;
            cout<<"Duplicate is: "<<arr[i]<<endl;
        }
    }
    return 0;
}