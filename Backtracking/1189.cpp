#include <bits/stdc++.h>

using namespace std;

int r, c, k;
int ans;
string s;
char board[10][10];
int visited[10][10];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

void go(int cnt, int y, int x)
{
    if (cnt == k - 1)
    {
        if (y == 0 && x == c - 1 && visited[y][x])
            ans++;
    }
    for (int i = 0; i < 4; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny >= r || nx >= c || ny < 0 || nx < 0)
            continue;
        if (visited[ny][nx] || board[ny][nx] == 'T')
            continue;
        visited[ny][nx]++;
        go(cnt + 1, ny, nx);
        visited[ny][nx]--;
    }
}
int main()
{
    cin >> r >> c >> k;
    for (int i = 0; i < r; i++)
    {
        cin >> s;
        for (int j = 0; j < c; j++)
            board[i][j] = s[j];
    }
    visited[r - 1][0]++;
    go(0, r - 1, 0);
    cout << ans;
}