#include <bits/stdc++.h>
using namespace std;
string minWindowSubstr(string s, string t)
{
    unordered_map<char, int> m;
    m.clear();
    for (int i = 0; i < t.length(); i++)
        m[t[i]]++;
    int count = m.size();
    int ans = INT_MAX;
    int i = 0;
    int j = 0;
    int start = 0;

    while (j < s.length())
    {
        m[s[j]]--;
        if (m[s[j]] == 0)
            count--;
        if (count == 0)
            while (count == 0)
            {
                if (ans > j - i + 1)
                {
                    ans = min(ans, j - i + 1);
                    start = i;
                }
                m[s[i]]++;
                if (m[s[i]] > 0)
                    count++;
                i++;
            }
        j++;
    }
    if (ans != INT_MAX)
        return s.substr(start, ans);
    else
        return "-1";
}
int main(void)
{
    string s = "ADOBECODEBANC";
    string t = "ABC";
    minWindowSubstr(s, t);
}