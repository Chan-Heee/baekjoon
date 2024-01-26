#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int map[102][102];
int n;
int m;
int k;
int result;
bool visited[102][102];

int main()
{
    cin >> m >> n >> k;

    int l_x;
    int l_y;
    int r_x;
    int r_y;
    queue<pair<int, int>> q;
    vector<int> v;
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};

    for (int i = 0; i < k; i++)
    {
        cin >> l_x >> l_y >> r_x >> r_y;
        for (int j = l_y + 1; j <= r_y; j++)
            for (int p = l_x + 1; p <= r_x; p++)
                map[p][j] = 1;
    }

    for (int j = 1; j <= m; j++)
        for (int i = 1; i <= n; i++)
        {
            if (!map[i][j] && !visited[i][j])
            {
                visited[i][j] = true;
                q.push({i, j});
                result++;
                while (!q.empty())
                {
                    pair<int, int> cur = q.front();
                    q.pop();
                    for (int k = 0; k < 4; k++)
                    {
                        int nx = cur.first + dx[k];
                        int ny = cur.second + dy[k];

                        if (nx < 1 || ny < 1 || nx > n || ny > m || visited[nx][ny] || map[nx][ny])
                            continue;

                        result++;
                        visited[nx][ny] = true;
                        q.push({nx, ny});
                    }
                }
                v.push_back(result);
                result = 0;
            }
        }
    sort(v.begin(), v.end());
    cout << v.size() << "\n";
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
}