#include <bits/stdc++.h>

using namespace std;
string s;
int n, m;
int x, y;
int board[104][104];
int visited[104][104];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int main()
{
    cin >> n >> m;
    cin.ignore();
    int idx = 0;
    while (idx < n && getline(cin, s))
    {
        for (int i = 0; i < s.length(); i++)
        {
            board[idx][i] = s[i] - '0';
        }
        idx++;
    }

    queue<pair<int, int>> q;
    q.push({0, 0});
    visited[0][0]++;

    while (!q.empty())
    {
        tie(y, x) = q.front();
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny < 0 || nx < 0 || ny >= n || nx >= m || visited[ny][nx] || !board[ny][nx])
                continue;

            visited[ny][nx] = visited[y][x] + 1;
            q.push({ny, nx});
        }
    }
    cout << visited[n - 1][m - 1];
}