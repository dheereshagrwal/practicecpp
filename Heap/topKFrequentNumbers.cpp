#include <bits/stdc++.h>
using namespace std;
void topKFrequentNumbers(int arr[], int n, int k)
{
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++)
        mp[arr[i]]++;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minh;
    for (auto i = mp.begin(); i != mp.end(); i++)
    {
        minh.push({i->second, i->first});
        if (minh.size() > k)
            minh.pop();
    }
    while (minh.size() > 0)
    {
        cout << minh.top().second << " ";
        minh.pop();
    }
}
