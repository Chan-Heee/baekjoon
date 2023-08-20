#include <iostream>
#include <queue>
#include <utility>
#include <algorithm>

using namespace std;
bool board[51][51];
int dist[51][51];
int MAX;
int dx[8] = {0, 1, -1, 0, -1, -1, 1, 1};
int dy[8] = {1, 0, 0, -1, 1, -1, 1, -1};
int main()
{
    int n, m;
    cin >> n >> m;
    queue<pair<int, int>> q;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            cin >> board[i][j];
            if (board[i][j])
                q.push({i, j});
        }

    while (!q.empty())
    {
        pair<int, int> cur = q.front();
        q.pop();
        for (int k = 0; k < 8; k++)
        {
            int nx = cur.first + dx[k];
            int ny = cur.second + dy[k];

            if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                continue;
            if (dist[nx][ny] || board[nx][ny])
                continue;
            dist[nx][ny] = dist[cur.first][cur.second] + 1;
            q.push({nx, ny});
        }
    }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            MAX = max(MAX, dist[i][j]);

    cout << MAX;
}