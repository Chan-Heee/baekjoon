#include <bits/stdc++.h>

using namespace std;

int a[54][54];
int visited[54][54];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int m, n, y, x, k, t;

void dfs(int y, int x)
{
    visited[y][x]++;
    for (int i = 0; i < 4; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (!visited[ny][nx] && nx >= 0 && ny >= 0 && nx < m && ny < n && a[ny][nx])
            dfs(ny, nx);
    }
    return;
}

int main()
{
    cin >> t;
    while (t--)
    {
        int ans = 0;
        cin >> m >> n >> k;
        for (int i = 0; i < k; i++)
        {
            cin >> x >> y;
            a[y][x] = 1;
        }
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
            {
                if (!visited[i][j] && a[i][j])
                {
                    dfs(i, j);
                    ans++;
                }
            }
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
            {
                visited[i][j] = 0;
                a[i][j] = 0;
            }
        cout << ans << '\n';
    }
}