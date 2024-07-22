#include <bits/stdc++.h>

using namespace std;

int n, m, ret, ans, mx;
int visited[12][12];
int a[12][12];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};
vector<pair<int, int>> v;

void dfs(int y, int x)
{
    visited[y][x] = 1;
    for (int i = 0; i < 4; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 0 || nx < 0 || nx >= m || ny >= n)
            continue;
        if (visited[ny][nx] || a[ny][nx] != 0)
            continue;

        ret--;
        dfs(ny, nx);
    }
}

int main()
{
    cin >> n >> m;
    ans = n * m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
            if (a[i][j] == 0)
                v.push_back({i, j});
            else
                ans--;
        }

    for (int i = 0; i < v.size() - 2; i++)
        for (int j = i + 1; j < v.size() - 1; j++)
            for (int k = j + 1; k < v.size(); k++)
            {
                ret = ans - 3;
                fill(&visited[0][0], &visited[0][0] + 12 * 12, 0);
                a[v[i].first][v[i].second] = 1;
                a[v[j].first][v[j].second] = 1;
                a[v[k].first][v[k].second] = 1;

                for (int p = 0; p < n; p++)
                    for (int q = 0; q < m; q++)
                    {
                        if (a[p][q] == 2 && !visited[p][q])
                            dfs(p, q);
                    }

                mx = max(mx, ret);

                a[v[i].first][v[i].second] = 0;
                a[v[j].first][v[j].second] = 0;
                a[v[k].first][v[k].second] = 0;
            }
    cout << mx;
}