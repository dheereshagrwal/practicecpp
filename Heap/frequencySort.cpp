#include <bits/stdc++.h>
using namespace std;
void topKFrequentNumbers(int arr[], int n)
{
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++)
        mp[arr[i]]++;
    priority_queue<pair<int, int>> maxh;
    for (auto i = mp.begin(); i != mp.end(); i++)
        maxh.push({i->second, i->first});

    while (maxh.size() > 0)
    {
        int freq = maxh.top().first;
        int val = maxh.top().second;
        for (int i = 0; i < freq; i++)
            cout << val << " ";
        maxh.pop();
    }
}
