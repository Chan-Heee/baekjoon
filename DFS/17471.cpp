#include <bits/stdc++.h>

using namespace std;

int n, tmp, to;
int adj[16][16];
int population[11];
int visited[16];
vector<int> selected;
vector<int> notselected;
const int INF = 2100000000;
int ans = INF;

int go(int here, vector<int> &v)
{
    int ret = 1;
    visited[here] = 1;
    for (int there = 1; there <= n; there++)
    {
        if (!visited[there] && (find(v.begin(), v.end(), there) != v.end()) && adj[here][there])
            ret += go(there, v);
    }
    return ret;
}

void dfs(int cnt, int last, int goal)
{
    if (cnt == goal)
    {
        notselected.clear();
        for (int i = 1; i <= n; i++)
        {
            if (find(selected.begin(), selected.end(), i) == selected.end())
                notselected.push_back(i);
        }
        memset(visited, 0, sizeof(visited));
        if (go(selected[0], selected) == selected.size() && go(notselected[0], notselected) == notselected.size())
        {
            int s_po = 0, n_po = 0;
            for (int i = 0; i < selected.size(); i++)
                s_po += population[selected[i]];
            for (int i = 0; i < notselected.size(); i++)
                n_po += population[notselected[i]];

            ans = min(ans, abs(s_po - n_po));
        }
        return;
    }
    for (int i = last + 1; i <= n; i++)
    {
        selected.push_back(i);
        dfs(cnt + 1, i, goal);
        selected.pop_back();
    }
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> population[i];

    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        for (int j = 0; j < tmp; j++)
        {
            cin >> to;
            adj[i + 1][to] = 1;
            adj[to][i + 1] = 1;
        }
    }
    for (int i = 1; i < n; i++)
    {
        dfs(0, 0, i);
    }
    (ans == INF) ? cout << -1 : cout << ans;
}
