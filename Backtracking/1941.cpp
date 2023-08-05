#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;
string board[5];
char result[5][5];
int print;

void dfs(int cnt, int last)
{
    if (cnt == 7)
    {
        queue<pair<int, int>> q;
        bool visited[5][5] = {
            false,
        };
        int S = 0;
        int num = 0;
        int dx[4] = {0, -1, 1, 0};
        int dy[4] = {1, 0, 0, -1};
        for (int i = 0; i < 25; i++)
        {
            if (result[i / 5][i % 5] != 0)
            {
                q.push({i / 5, i % 5});
                visited[i / 5][i % 5] = true;
                if (result[i / 5][i % 5] == 'S')
                    S++;
                num++;
                break;
            }
        }
        while (!q.empty())
        {
            pair<int, int> cur = q.front();
            q.pop();
            for (int i = 0; i < 4; i++)
            {
                int nx = cur.first + dx[i];
                int ny = cur.second + dy[i];

                if (nx < 0 || ny < 0 || nx >= 5 || ny >= 5)
                    continue;
                if (visited[nx][ny] || (result[nx][ny] != 'S' && result[nx][ny] != 'Y'))
                    continue;
                if (result[nx][ny] == 'S')
                    S++;
                num++;
                q.push({nx, ny});
                visited[nx][ny] = true;
            }
        }
        if (S >= 4 && num == 7)
            print++;
        return;
    }
    for (int i = last + 1; i < 25; i++)
    {
        int nx = i / 5;
        int ny = i % 5;

        result[nx][ny] = board[nx][ny];
        last = i;
        dfs(cnt + 1, last);
        result[nx][ny] = 0;
    }
}
int main()
{
    for (int i = 0; i < 5; i++)
        cin >> board[i];
    dfs(0, -1);
    cout << print;
}