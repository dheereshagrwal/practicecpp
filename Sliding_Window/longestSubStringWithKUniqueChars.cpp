#include <bits/stdc++.h>
using namespace std;
int longestSubStringWithKUniqueChars(string s)
{
    unordered_map<char, int> mp;
    mp.clear();
    list<char> l;
    int i = 0;
    int j = 0;
    int k = 3;
    int mx = INT_MIN;

    while (j < s.length())
    {
        mp[s[j]]++;
        if (mp.size() < k)
            j++;
        else if (mp.size() == k)
        {
            mx = max(mx, k);
            j++;
        }
        else if (mp.size() > k)
        {
            while (mp.size() > k)
            {
                mp[s[i]]--;
                if (mp[s[i]] == 0)
                    mp.erase(s[i]);
                i++;
            }
            j++;
        }
    }
    return mx;
}