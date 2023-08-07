#include <iostream>
#include <queue>
#include <utility>
#include <string>

using namespace std;

string board[1001];
int dist[1001][1001];
bool visited_j[1001][1001];
bool visited_f[1001][1001];

int main()
{
    int r, c;
    cin >> r >> c;
    for (int i = 0; i < r; i++)
        cin >> board[i];
    queue<pair<int, int>> fire;
    queue<pair<int, int>> jihoon;
    int dx[4] = {0, 1, -1, 0};
    int dy[4] = {1, 0, 0, -1};
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
        {
            if (board[i][j] == 'J')
            {
                jihoon.push({i, j});
                visited_j[i][j] = true;
                dist[i][j] = 1;
            }
            if (board[i][j] == 'F')
            {
                fire.push({i, j});
                visited_f[i][j] = true;
            }
        }
    while (!jihoon.empty())
    {
        int cur_fsize = fire.size();
        for (int i = 0; i < cur_fsize; i++)
        {
            pair<int, int> cur_f = fire.front();
            fire.pop();
            for (int i = 0; i < 4; i++)
            {
                int nx = cur_f.first + dx[i];
                int ny = cur_f.second + dy[i];

                if (nx < 0 || ny < 0 || nx >= r || ny >= c)
                    continue;
                if (visited_f[nx][ny] || board[nx][ny] == '#')
                    continue;
                board[nx][ny] = 'F';
                visited_f[nx][ny] = true;
                fire.push({nx, ny});
            }
        }
        int cur_jsize = jihoon.size();
        for (int i = 0; i < cur_jsize; i++)
        {
            pair<int, int> cur_j = jihoon.front();
            jihoon.pop();

            for (int i = 0; i < 4; i++)
            {
                int nx = cur_j.first + dx[i];
                int ny = cur_j.second + dy[i];

                if (nx < 0 || ny < 0 || nx >= r || ny >= c)
                    continue;
                if (visited_j[nx][ny] || board[nx][ny] == '#' || board[nx][ny] == 'F')
                    continue;
                visited_j[nx][ny] = true;
                dist[nx][ny] = dist[cur_j.first][cur_j.second] + 1;
                jihoon.push({nx, ny});
            }
        }
    }
    int result = 100000000;
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
        {
            if ((i == 0 || i == r - 1 || j == 0 || j == c - 1) && dist[i][j] > 0)
                result = min(result, dist[i][j]);
        }
    if (result < 100000000)
        cout << result;
    else
        cout << "IMPOSSIBLE";
}