#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int map[10][10];
int cp[10][10];
bool visited[10][10];
bool visited2[10][10];
int n, m;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int ans;

void dfs(int cnt, int next)
{
    if (cnt == 3)
    {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cp[i][j] = map[i][j];

        queue<pair<int, int>> q;
        int result = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (cp[i][j] == 2 && !visited2[i][j])
                {
                    q.push({i, j});
                    visited2[i][j] = true;
                    while (!q.empty())
                    {
                        pair<int, int> cur = q.front();
                        q.pop();
                        for (int k = 0; k < 4; k++)
                        {
                            int nx = cur.first + dx[k];
                            int ny = cur.second + dy[k];

                            if (nx < 0 || ny < 0 || nx >= n || ny >= m)
                                continue;
                            if (visited2[nx][ny] || cp[nx][ny] != 0)
                                continue;

                            cp[nx][ny] = 2;
                            visited2[nx][ny] = true;
                            q.push({nx, ny});
                        }
                    }
                }
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (cp[i][j] == 0)
                    result++;
                visited2[i][j] = false;
            }
        }
        ans = max(ans, result);

        return;
    }

    for (int i = next + 1; i < n * m; i++)
    {
        int x = i / m;
        int y = i % m;
        if (!visited[x][y] && map[x][y] == 0)
        {
            map[x][y] = 1;
            visited[x][y] = true;
            dfs(cnt + 1, i);
            visited[x][y] = false;
            map[x][y] = 0;
        }
    }
}

int main()
{

    cin >> n >> m;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            cin >> map[i][j];
        }

    dfs(0, -1);

    cout << ans;
}