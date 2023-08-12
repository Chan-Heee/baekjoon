#include <iostream>
#include <queue>
#include <utility>
#include <string>

using namespace std;
string board1[105];
char board2[105][105];
bool visited1[101][101];
bool visited2[101][101];

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> board1[i];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            if (board1[i][j] == 'G')
                board2[i][j] = 'R';
            else
                board2[i][j] = board1[i][j];
        }
    queue<pair<int, int>> q1;
    queue<pair<int, int>> q2;
    int result1 = 0;
    int result2 = 0;
    int dx[4] = {0, 1, -1, 0};
    int dy[4] = {1, 0, 0, -1};
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            if (!visited1[i][j])
            {
                q1.push({i, j});
                visited1[i][j] = true;
                result1++;
                while (!q1.empty())
                {
                    pair<int, int> cur = q1.front();
                    q1.pop();
                    for (int k = 0; k < 4; k++)
                    {
                        int nx = cur.first + dx[k];
                        int ny = cur.second + dy[k];

                        if (nx < 0 || ny < 0 || nx >= n || ny >= n)
                            continue;
                        if (visited1[nx][ny] || (board1[i][j] != board1[nx][ny]))
                            continue;
                        visited1[nx][ny] = true;
                        q1.push({nx, ny});
                    }
                }
            }
            if (!visited2[i][j])
            {
                q2.push({i, j});
                visited2[i][j] = true;
                result2++;
                while (!q2.empty())
                {
                    pair<int, int> cur = q2.front();
                    q2.pop();
                    for (int k = 0; k < 4; k++)
                    {
                        int nx = cur.first + dx[k];
                        int ny = cur.second + dy[k];

                        if (nx < 0 || ny < 0 || nx >= n || ny >= n)
                            continue;
                        if (visited2[nx][ny] || (board2[i][j] != board2[nx][ny]))
                            continue;
                        visited2[nx][ny] = true;
                        q2.push({nx, ny});
                    }
                }
            }
        }
    cout << result1 << " " << result2;
}