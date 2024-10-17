#include <bits/stdc++.h>

using namespace std;
int r, c, ans;
char board[34][34];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int visited[30];
string s;

void dfs(int y, int x, int sum)
{
    visited[board[y][x] - 'A'] = 1;
    ans = max(sum, ans);
    for (int i = 0; i < 4; i++)
    {
        int ny = dy[i] + y;
        int nx = dx[i] + x;

        if (ny < 0 || nx < 0 || ny >= r || nx >= c || visited[board[ny][nx] - 'A'])
            continue;
        dfs(ny, nx, sum + 1);
        visited[board[ny][nx] - 'A'] = 0;
    }
}

int main()
{
    cin >> r >> c;
    for (int i = 0; i < r; i++)
    {
        cin >> s;
        for (int j = 0; j < c; j++)
            board[i][j] = s[j];
    }
    dfs(0, 0, 1);
    cout << ans;
}