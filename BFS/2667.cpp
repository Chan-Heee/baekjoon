#include <iostream>
#include <queue>
#include <algorithm>
#include <utility>

using namespace std;

int map[27][27];
bool visited[27][27];
vector<int> num;

int main()
{
    int n;
    int dx[4] = {0, 1, -1, 0};
    int dy[4] = {1, 0, 0, -1};
    int idx = 0;
    cin >> n;
    string in;
    for (int i = 0; i < n; i++)
    {
        cin >> in;
        for (int j = 0; j < n; j++)
            map[i][j] = in[j] - '0';
    }

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            queue<pair<int, int>> q;
            if (!visited[i][j] && map[i][j] != 0)
            {
                visited[i][j] = true;
                q.push({i, j});
                num.push_back(1);
                while (!q.empty())
                {
                    pair<int, int> cur = q.front();
                    q.pop();
                    for (int k = 0; k < 4; k++)
                    {
                        int nx = cur.first + dx[k];
                        int ny = cur.second + dy[k];

                        if (nx < 0 || ny < 0 || nx >= n || ny >= n)
                            continue;
                        if (visited[nx][ny] || map[nx][ny] != map[i][j])
                            continue;
                        visited[nx][ny] = true;
                        q.push({nx, ny});
                        num[idx]++;
                    }
                }
                idx++;
            }
        }
    cout << num.size() << "\n";
    sort(num.begin(), num.end());
    for (int i = 0; i < num.size(); i++)
    {
        cout << num[i] << "\n";
    }
}