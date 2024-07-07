#include <bits/stdc++.h>

using namespace std;

int n;
int a[104][104];
int visited[104][104];
int ans;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {-1, 1, 0, 0};

void dfs(int y, int x, int r)
{
    visited[y][x]++;
    for (int i = 0; i < 4; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 0 || nx < 0 || nx >= n || ny >= n || visited[ny][nx] || ((a[ny][nx] - r) <= 0))
            continue;
        dfs(ny, nx, r);
    }
    return;
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> a[i][j];

    int r = 100;
    while (r-- >= 0)
    {
        fill(&visited[0][0], &visited[0][0] + 104 * 104, 0);
        int ret = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
            {
                if (!visited[i][j] && ((a[i][j] - r) > 0))
                {
                    dfs(i, j, r);
                    ret++;
                }
            }
        ans = max(ans, ret);
    }
    cout << ans;
}