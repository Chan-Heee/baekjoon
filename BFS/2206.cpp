#include <iostream>
#include <tuple>
#include <queue>

using namespace std;

int map[1002][1002];
int dist[1002][1002][2];
bool visited[1002][1002][2];

int main()
{
    int m, n;
    cin >> m >> n;
    string in;
    for (int i = 0; i < m; i++)
    {
        cin >> in;
        for (int j = 0; j < n; j++)
        {
            map[i][j] = in[j] - '0';
        }
    }
    int dx[4] = {0, 1, -1, 0};
    int dy[4] = {1, 0, 0, -1};
    queue<tuple<int, int, int>> q;
    q.push({0, 0, 0});
    visited[0][0][0] = true;
    visited[0][0][1] = true;
    while (!q.empty())
    {
        tuple<int, int, int> cur = q.front();
        q.pop();

        if (get<0>(cur) == m - 1 && get<1>(cur) == n - 1)
        {
            cout << dist[m - 1][n - 1][get<2>(cur)] + 1;
            return 0;
        }

        for (int i = 0; i < 4; i++)
        {
            int nx = get<0>(cur) + dx[i];
            int ny = get<1>(cur) + dy[i];

            if (nx < 0 || ny < 0 || nx >= m || ny >= n)
                continue;
            if (get<2>(cur) == 1 && (visited[nx][ny][0] || visited[nx][ny][1]))
                continue;
            if (get<2>(cur) == 0 && visited[nx][ny][0])
                continue;
            if (map[nx][ny] == 1 && get<2>(cur) == 0)
            {
                visited[nx][ny][1] = true;
                dist[nx][ny][1] = dist[get<0>(cur)][get<1>(cur)][0] + 1;
                q.push({nx, ny, 1});
            }
            if (map[nx][ny] == 0)
            {
                visited[nx][ny][get<2>(cur)] = true;
                dist[nx][ny][get<2>(cur)] = dist[get<0>(cur)][get<1>(cur)][get<2>(cur)] + 1;
                q.push({nx, ny, get<2>(cur)});
            }
        }
    }
    cout << -1;
}