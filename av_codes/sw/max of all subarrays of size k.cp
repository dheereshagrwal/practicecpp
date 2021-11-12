#include <list>
vector<int> Solution::slidingMaximum(const vector<int> &v, int k) {
    vector<int> ans;
    if(k>v.size())
    {
        ans.push_back(*max_element(v.begin(),v.end()));
        return ans;
    }
    
    int i=0;
    int j=0;
    int size=v.size();
    list<int> l;
    
    while(j<size)
    {
        //calculations
        while(l.size()>0 && l.back()<v[j])
        {
            l.pop_back();
        }
        l.push_back(v[j]);
        
        
        if(j-i+1<k)
        {
            j++;
        }
        else if(j-i+1==k)
        {
            // ans <--- calculations
            ans.push_back(l.front());
            
            
            
            //slide the window
            if(l.front()==v[i]){
                l.pop_front();
            }
            i++;
            j++;
            
        }
    }
    
    return ans;
}

