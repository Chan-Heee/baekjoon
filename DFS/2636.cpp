#include <bits/stdc++.h>

using namespace std;
int n, m, ret, cnt, next_cnt;
int a[104][104];
int next_a[104][104];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
bool visited[104][104];

void dfs(int y, int x)
{
    if (visited[y][x])
        return;
    visited[y][x] = true;
    for (int i = 0; i < 4; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (nx < 0 || ny < 0 || nx >= m || ny >= n)
            continue;
        if (a[ny][nx] == 1)
            continue;
        dfs(ny, nx);
    }
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
            if (a[i][j])
                cnt++;
        }

    next_cnt = cnt;
    while (1)
    {
        ret++;
        dfs(0, 0);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
            {
                bool flag = false;
                if (!a[i][j])
                    continue;
                for (int k = 0; k < 4; k++)
                {
                    int ny = i + dy[k];
                    int nx = j + dx[k];

                    if (nx < 0 || ny < 0 || nx >= m || ny >= n)
                        continue;
                    if (visited[ny][nx])
                        flag = true;
                }
                (flag) ? next_a[i][j] = 0, next_cnt-- : next_a[i][j] = a[i][j];
            }
        if (next_cnt == 0)
        {
            cout << ret << '\n';
            cout << cnt;
            break;
        }
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
            {
                visited[i][j] = false;
                a[i][j] = next_a[i][j];
            }
        cnt = next_cnt;
    }
}