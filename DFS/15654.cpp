#include <bits/stdc++.h>

using namespace std;

int n, m, tmp;
vector<int> v;
int visited[12];
vector<int> ret;

void dfs(int cnt)
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
        if (!visited[i])
        {
            ret.push_back(v[i]);
            visited[i] = 1;
            dfs(cnt + 1);
            visited[i] = 0;
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
    dfs(0);
}