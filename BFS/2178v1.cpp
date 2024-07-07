#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

int n, m;
int board[101][101];
int dist[101][101];
bool visited[101][101];

int main()
{
    cin >> n >> m;
    string in;
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    for (int i = 0; i < n; i++)
    {
        cin >> in;
        for (int j = 0; j < m; j++)
        {
            board[i][j] = in[j] - '0';
        }
    }
    queue<pair<int, int>> q;
    q.push({0, 0});
    visited[0][0] = true;
    dist[0][0] = 1;
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
            if (visited[nx][ny] || board[nx][ny] != 1)
                continue;
            dist[nx][ny] = dist[cur.first][cur.second] + 1;
            q.push({nx, ny});
            visited[nx][ny] = true;
        }
    }
    cout << dist[n - 1][m - 1];
}