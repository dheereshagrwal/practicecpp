#include <bits/stdc++.h>
using namespace std;
int longestSubStringWithAllUniqueChars(string s)
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
        if (mp.size() == j - i + 1)
            mx = max(mx, k);
        else if (mp.size() < j - i + 1)
        {
            while (mp.size() < j - i + 1)
            {
                mp[s[i]]--;
                if (mp[s[i]] == 0)
                    mp.erase(s[i]);
                i++;
            }
        }
        j++;
    }
    return mx;
}