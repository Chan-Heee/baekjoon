#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

int m, n;
int tomato[1001][1001];
int dist[1001][1001];
int num;

int ft_check()
{
    int MAX = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            if (tomato[i][j] == 0)
                return -1;
            MAX = max(MAX, dist[i][j]);
        }
    return MAX;
}
int main()
{
    cin >> m >> n;
    queue<pair<int, int>> q;
    int dx[4] = {0, 1, -1, 0};
    int dy[4] = {1, 0, 0, -1};
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            cin >> tomato[i][j];
            if (tomato[i][j] == 1)
                q.push({i, j});
        }
    while (!q.empty())
    {
        pair<int, int> cur = q.front();
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];

            if (nx < 0 || ny < 0 || nx >= n || ny >= m)
                continue;
            if (tomato[nx][ny] == 1 || tomato[nx][ny] == -1)
                continue;
            tomato[nx][ny] = 1;
            dist[nx][ny] = dist[cur.first][cur.second] + 1;
            q.push({nx, ny});
        }
    }
    cout << ft_check();
}