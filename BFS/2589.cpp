#include <bits/stdc++.h>

using namespace std;

int n, m, ret;
string s;
char a[51][51];
queue<pair<int, int>> q;
int visited[51][51];
int dy[4] = {0, 0, 1, -1};
int dx[4] = {1, -1, 0, 0};
int mx[51][51];

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> s;
        for (int j = 0; j < m; j++)
            a[i][j] = s[j];
    }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            if (a[i][j] == 'L')
            {
                fill(&visited[0][0], &visited[0][0] + 51 * 51, 0);
                q.push({i, j});
                visited[i][j] = 1;
                mx[i][j] = 1;
                while (!q.empty())
                {
                    pair<int, int> cur = q.front();
                    q.pop();
                    for (int k = 0; k < 4; k++)
                    {
                        int ny = cur.first + dy[k];
                        int nx = cur.second + dx[k];

                        if (ny < 0 || nx < 0 || nx >= m || ny >= n || visited[ny][nx] || a[ny][nx] != 'L')
                            continue;

                        visited[ny][nx] = visited[cur.first][cur.second] + 1;
                        mx[ny][nx] = max(mx[ny][nx], visited[ny][nx]);
                        q.push({ny, nx});
                    }
                }
            }
        }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            ret = max(ret, mx[i][j]);
    cout << ret - 1;
}