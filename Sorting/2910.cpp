#include <bits/stdc++.h>

using namespace std;

int n, c;
map<int, int> mp;
map<int, int> f;
vector<pair<int, int>> ap;
int tmp;

bool cmp(pair<int, int> a, pair<int, int> b)
{
    if (a.first == b.first)
    {
        return f[a.second] < f[b.second];
    }
    return a.first > b.first;
}

int main()
{
    cin >> n >> c;
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        if (!mp[tmp])
            f[tmp] = i + 1;
        mp[tmp]++;
    }
    for (auto k : mp)
    {
        ap.push_back({k.second, k.first});
    }
    sort(ap.begin(), ap.end(), cmp);
    for (auto k : ap)
    {
        for (int i = 0; i < k.first; i++)
        {
            cout << k.second << " ";
        }
    }
}