#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

char map[13][7];
bool flag = true;
bool visited[13][7];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};
int ans;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for (int i = 0; i < 12; i++)
    {
        string tmp;
        cin >> tmp;
        for (int j = 0; j < 6; j++)
            map[i][j] = tmp[j];
    }

    while (flag)
    {
        flag = false;

        for (int i = 0; i < 12; i++)
        {
            for (int j = 0; j < 6; j++)
            {
                if (map[i][j] != '.')
                {
                    queue<pair<int, int>> tmp;
                    queue<pair<int, int>> q;
                    q.push({i, j});
                    tmp.push({i, j});
                    visited[i][j] = true;
                    while (!q.empty())
                    {
                        pair<int, int> cur = q.front();
                        q.pop();
                        for (int k = 0; k < 4; k++)
                        {
                            int nx = cur.first + dx[k];
                            int ny = cur.second + dy[k];

                            if (nx < 0 || ny < 0 || nx >= 12 || ny >= 6)
                                continue;
                            if (visited[nx][ny] || map[nx][ny] != map[i][j])
                                continue;

                            visited[nx][ny] = true;
                            q.push({nx, ny});
                            tmp.push({nx, ny});
                        }
                    }
                    if (tmp.size() >= 4)
                    {
                        while (!tmp.empty())
                        {
                            pair<int, int> cur = tmp.front();
                            tmp.pop();
                            map[cur.first][cur.second] = '.';
                        }
                        flag = true;
                    }
                }
                for (int m = 0; m < 12; m++)
                    for (int l = 0; l < 6; l++)
                        visited[m][l] = false;
            }
        }
        for (int i = 11; i > 0; i--)
            for (int j = 0; j < 6; j++)
            {
                if (map[i][j] != '.')
                    continue;

                int tmp = i - 1;
                while (map[tmp][j] == '.')
                {
                    if (tmp == 0)
                        break;
                    tmp--;
                }
                map[i][j] = map[tmp][j];
                map[tmp][j] = '.';
            }
        if (flag)
            ans++;
    }
    cout << ans;
}