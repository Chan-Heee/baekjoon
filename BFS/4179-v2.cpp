// 불부터 bfs 순회하면서 각 칸에 도달하는 최소시간을 구한다.
// 지훈이가 그 이후에 순회하면서 불이 도달하는 최소시간이랑 비교해서 짧으면 이동하고 아니면 이동하지않는다.
// 마지막 확인시 지훈이가 도달한 시간 +1 출력, 지훈이가 도달하지못했으면 임파서블 출력한다.

#include <bits/stdc++.h>

using namespace std;

int r, c, ans, flag;
string s;
char board[1004][1004];
int fire[1004][1004];
int jihoon[1004][1004];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
queue<pair<int, int>> q_fire;
queue<pair<int, int>> q_jihoon;

int main()
{
    cin >> r >> c;
    for (int i = 0; i < r; i++)
    {
        cin >> s;
        for (int j = 0; j < c; j++)
        {
            board[i][j] = s[j];
            if (s[j] == 'F')
            {
                q_fire.push({i, j});
                fire[i][j]++;
            }
            else if (s[j] == 'J')
            {
                if (i == 0 || i == r - 1 || j == 0 || j == c - 1)
                    flag = 1;
                q_jihoon.push({i, j});
                jihoon[i][j]++;
            }
        }
    }
    if (flag)
    {
        cout << 1;
        return 0;
    }
    while (!q_fire.empty())
    {
        pair<int, int> cur = q_fire.front();
        q_fire.pop();
        for (int k = 0; k < 4; k++)
        {
            int ny = cur.first + dy[k];
            int nx = cur.second + dx[k];

            if (ny < 0 || nx < 0 || ny >= r || nx >= c)
                continue;
            if (fire[ny][nx] || board[ny][nx] == '#')
                continue;

            fire[ny][nx] = fire[cur.first][cur.second] + 1;
            q_fire.push({ny, nx});
        }
    }
    while (!q_jihoon.empty())
    {
        pair<int, int> cur = q_jihoon.front();
        q_jihoon.pop();
        for (int k = 0; k < 4; k++)
        {
            int ny = cur.first + dy[k];
            int nx = cur.second + dx[k];

            if (ny < 0 || nx < 0 || ny >= r || nx >= c)
                continue;
            if (jihoon[ny][nx] || board[ny][nx] != '.')
                continue;
            if ((fire[ny][nx] != 0) && jihoon[cur.first][cur.second] + 1 >= fire[ny][nx])
                continue;
            if (ny == 0 || ny == r - 1 || nx == 0 || nx == c - 1)
            {
                ans = jihoon[cur.first][cur.second] + 1;
                cout << ans;
                return 0;
            }
            jihoon[ny][nx] = jihoon[cur.first][cur.second] + 1;
            q_jihoon.push({ny, nx});
        }
    }
    cout << "IMPOSSIBLE";
}
