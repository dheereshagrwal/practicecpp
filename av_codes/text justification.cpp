
bool check(int currlen, int length, int mx,int i,int j)
{
    return (currlen+length+j-i)<=mx;
}

string fully(int i,int j,int evenly,int extra, vector<string>& arr)
{
    string s="";
    for(int k =i; k<j; k++)
    {
        s=s+arr[k];
        if(k==j-1)
        {
            break;
        }
        for(int l =0;l<evenly;l++)
        {
            s.push_back(' ');
        }
        if(extra>0)
        {
            s.push_back(' ');
            extra--;
        }
     
    }
    
    return s;
    
}

string left(int i,int j, int spaces, vector<string>& arr)
{
    string s="";
    for(int k=i;k<j;k++)
    {
        s=s+arr[k];
        if(k==j-1)
        {
            break;
        }
        s.push_back(' ');
        spaces--;
    }
    
    for(int k=0;k<spaces;k++)
    {
        s.push_back(' ');
    }
    
    return s;
    
}

class Solution {
public:
    vector<string> fullJustify(vector<string>& arr, int mx) {
        
        int i=0;
        int j=0;
        vector<string> ans;
        
        while(j<arr.size())
        {
            bool lastline =false;
            int currlen =0;
            while(j<arr.size() && check(currlen,arr[j].length(),mx,i,j)==true)
            {
                currlen =currlen + arr[j].length();
                j++;
            }
            
            if(j==arr.size())
            {
                lastline =true;
            }
            int evenly =0;
            int extra = 0;
            int spaces = mx-currlen;
            int nword = j-i;
            if(nword > 1)
            {
                 evenly = spaces/(nword-1);
                 extra = spaces%(nword-1);
            }
            else
            {
                lastline =true;
            }

            string s;
            if(lastline ==false)
            {
                 s = fully(i,j,evenly,extra,arr);
            }
            else
            {
                 s =left(i,j,spaces, arr);
            }
            ans.push_back(s);
            
            i=j;
        }
        
        return ans;
        
    }
};
