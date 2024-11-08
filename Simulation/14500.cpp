#include <bits/stdc++.h>

using namespace std;

int n, m, ans;
int board[510][510];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int visited[510][510];

void checkSpecialShape(int y, int x)
{
    // ㅜ 모양
    if (x - 1 >= 0 && x + 1 < m && y + 1 < n)
        ans = max(ans, board[y][x] + board[y][x - 1] + board[y][x + 1] + board[y + 1][x]);
    // ㅓ 모양
    if (x - 1 >= 0 && y - 1 >= 0 && y + 1 < n)
        ans = max(ans, board[y][x] + board[y - 1][x] + board[y + 1][x] + board[y][x - 1]);
    // ㅗ 모양
    if (x - 1 >= 0 && x + 1 < m && y - 1 >= 0)
        ans = max(ans, board[y][x] + board[y][x - 1] + board[y][x + 1] + board[y - 1][x]);
    // ㅏ 모양
    if (x + 1 < m && y - 1 >= 0 && y + 1 < n)
        ans = max(ans, board[y][x] + board[y - 1][x] + board[y + 1][x] + board[y][x + 1]);
}

void go(int y, int x, int cnt, int sum)
{
    if (cnt == 4)
    {
        ans = max(ans, sum);
        return;
    }
    for (int i = 0; i < 4; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 0 || nx < 0 || ny >= n || nx >= m || visited[ny][nx])
            continue;
        visited[ny][nx] = 1;
        go(ny, nx, cnt + 1, sum + board[ny][nx]);
        visited[ny][nx] = 0;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> board[i][j];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            visited[i][j] = 1;
            go(i, j, 1, board[i][j]);
            visited[i][j] = 0;
            checkSpecialShape(i, j);
        }
    cout << ans;
}