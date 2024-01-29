#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int n, m;
int map[301][301];
int result_map[301][301];
bool visited[301][301];
queue<pair<int, int>> q;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> map[i][j];

    int count = 0;
    while (true)
    {
        int land = 0;
        memset(visited, false, sizeof(visited));
        memset(result_map, 0, sizeof(result_map));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (map[i][j] > 0 && !visited[i][j])
                {
                    land++;
                    visited[i][j] = true;
                    q.push({i, j});
                    while (!q.empty())
                    {
                        pair<int, int> cur = q.front();
                        q.pop();
                        for (int k = 0; k < 4; k++)
                        {
                            int nx = cur.first + dx[k];
                            int ny = cur.second + dy[k];

                            if (nx < 0 || ny < 0 || nx >= n || ny >= m || visited[nx][ny] || map[nx][ny] <= 0)
                                continue;

                            visited[nx][ny] = true;
                            q.push({nx, ny});
                        }
                    }
                }
            }
        }
        if (land >= 2)
        {
            cout << count;
            break;
        }

        if (land == 0)
        {
            cout << 0;
            break;
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (map[i][j] > 0)
                {
                    result_map[i][j] = map[i][j];
                    for (int k = 0; k < 4; k++)
                    {
                        int nx = i + dx[k];
                        int ny = j + dy[k];

                        if (nx < 0 || ny < 0 || nx >= n || ny >= m)
                            continue;
                        if (map[nx][ny] <= 0)
                            result_map[i][j] = result_map[i][j] - 1;
                    }
                }
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                map[i][j] = result_map[i][j];
            }
        }
        count++;
    }
}