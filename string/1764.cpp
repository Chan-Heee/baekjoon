#include <bits/stdc++.h>

using namespace std;
int n, m;
string s;
map<string, int> mp;
vector<string> v;

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> s;
        mp[s]++;
    }
    for (int i = 0; i < m; i++)
    {
        cin >> s;
        if (mp[s] != 0)
            v.push_back(s);
    }
    sort(v.begin(), v.end());
    cout << v.size() << '\n';
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << '\n';
}