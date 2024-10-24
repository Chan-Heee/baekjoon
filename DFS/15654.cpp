#include <bits/stdc++.h>

using namespace std;

int n, m, tmp;
vector<int> v;
int visited[12];
vector<int> ret;

void dfs(int cnt, int last)
{
    if (cnt == m)
    {
        for (int i : ret)
            cout << i << ' ';
        cout << '\n';
        return;
    }
    for (int i = 0; i < v.size(); i++)
    {
        if (last <= v[i])
        {
            ret.push_back(v[i]);
            dfs(cnt + 1, v[i]);
            ret.pop_back();
        }
    }
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        v.push_back(tmp);
    }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    dfs(0, -1);
}