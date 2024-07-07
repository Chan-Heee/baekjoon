#include <iostream>
#include <queue>
#include <utility>

using namespace std;

int board[51][51];
bool visited[51][51];

int main()
{
    int c;
    int m, n;
    int cabbage;
    int dx[4] = {0, 1, -1, 0};
    int dy[4] = {1, 0, 0, -1};
    cin >> c;
    while (c--)
    {
        cin >> n >> m >> cabbage;
        int l, k;
        int result = 0;
        while (cabbage-- > 0)
        {
            cin >> k >> l;
            board[l][k] = 1;
        }
        queue<pair<int, int>> q;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
            {
                int flag = 0;
                if (board[i][j] == 1 && !visited[i][j])
                {
                    visited[i][j] = true;
                    q.push({i, j});
                    flag = 1;
                }
                while (!q.empty())
                {
                    pair<int, int> cur = q.front();
                    q.pop();
                    for (int i = 0; i < 4; i++)
                    {
                        int nx = cur.first + dx[i];
                        int ny = cur.second + dy[i];

                        if (nx < 0 || ny < 0 || nx >= m || ny >= n)
                            continue;
                        if (visited[nx][ny] || board[nx][ny] != 1)
                            continue;
                        visited[nx][ny] = true;
                        q.push({nx, ny});
                    }
                }
                if (flag)
                    result++;
            }
        for (int i = 0; i <= 50; i++)
            for (int j = 0; j <= 50; j++)
            {
                board[i][j] = 0;
                visited[i][j] = 0;
            }
        cout << result << '\n';
    }
}