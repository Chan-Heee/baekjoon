#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int board[501][501];
bool visited[501][501];
int row;
int column;
int num = 0;
int MAX = 0;

int main()
{
    int dx[4] = {0, -1, 0, 1};
    int dy[4] = {1, 0, -1, 0};
    cin >> row >> column;
    for (int i = 0; i < row; i++)
        for (int j = 0; j < column; j++)
            cin >> board[i][j];
    queue<pair<int, int>> q;
    for (int i = 0; i < row; i++)
        for (int j = 0; j < column; j++)
        {
            if (visited[i][j] || board[i][j] != 1)
                continue;
            q.push({i, j});
            visited[i][j] = true;
            int width = 1;
            while (!q.empty())
            {
                pair<int, int> cur = q.front();
                q.pop();
                for (int i = 0; i < 4; i++)
                {
                    int nx = cur.first + dx[i];
                    int ny = cur.second + dy[i];
                    if (nx < 0 || ny < 0 || nx > row - 1 || ny > column - 1)
                        continue;
                    if (visited[nx][ny] || board[nx][ny] != 1)
                        continue;
                    visited[nx][ny] = true;
                    width++;
                    q.push({nx, ny});
                }
            }
            MAX = max(MAX, width);
            num++;
        }
    cout << num << "\n";
    cout << MAX;
}