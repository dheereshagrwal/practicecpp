	int search(string ptr, string s) {
	    unordered_map<char,int> mp;
        for(int i=0;i<ptr.length();i++)
        {
            mp[ptr[i]]++;
        }
        int count=mp.size();
        int i=0;
        int j=0;
        int ans=0;
        int k =ptr.length();
        while(j<s.length())
        {
            if(mp.find(s[j])!=mp.end())
            {
                mp[s[j]]--;
                if(mp[s[j]]==0)
                {
                    count--;
                }
            }
           
            if(j-i+1<k)
            {
                j++;
            }
            else if(j-i+1==k)
            {
            if(count==0)
            {
                ans++;
            }
                if(mp.find(s[i])!=mp.end())
                {
                mp[s[i]]++;
                if(mp[s[i]]==1)
                {
                    count++;
                }
                }
                i++;
                j++;
            }
        }
        return ans;
	}