#include <iostream>
#include <queue>
#include <tuple>
#include <algorithm>

using namespace std;

int n, m, h;
int board[102][102][102];
bool visited[102][102][102];
int score[102][102][102];
int dx[6] = {0, 0, 1, -1, 0, 0};
int dy[6] = {0, 0, 0, 0, 1, -1};
int dz[6] = {1, -1, 0, 0, 0, 0};
int ans;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    queue<tuple<int, int, int>> q;
    int zero = 0;
    cin >> m >> n >> h;
    for (int i = 0; i < h; i++)
        for (int j = 0; j < n; j++)
            for (int k = 0; k < m; k++)
            {
                cin >> board[j][k][i];
                if (board[j][k][i] == 0)
                    zero++;
                if (board[j][k][i] == 1)
                {
                    visited[j][k][i] = true;
                    q.push({j, k, i});
                }
            }
    if (zero == 0)
    {
        cout << 0;
        return 0;
    }

    while (!q.empty())
    {
        int days = 0;

        tuple<int, int, int> cur = q.front();
        q.pop();

        for (int l = 0; l < 6; l++)
        {
            int nx = get<0>(cur) + dx[l];
            int ny = get<1>(cur) + dy[l];
            int nz = get<2>(cur) + dz[l];

            if (nx < 0 || ny < 0 || nz < 0 || nx >= n || ny >= m || nz >= h || visited[nx][ny][nz])
                continue;

            if (board[nx][ny][nz] == -1 || board[nx][ny][nz] == 1)
                continue;

            score[nx][ny][nz] = score[get<0>(cur)][get<1>(cur)][get<2>(cur)] + 1;
            board[nx][ny][nz] = 1;
            visited[nx][ny][nz] = true;
            q.push({nx, ny, nz});
        }
    }
    for (int i = 0; i < h; i++)
        for (int j = 0; j < n; j++)
            for (int k = 0; k < m; k++)
            {
                if (!board[j][k][i])
                {
                    cout << -1;
                    return 0;
                }
                ans = max(ans, score[j][k][i]);
            }
    cout << ans;
}
