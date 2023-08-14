#include <iostream>
#include <queue>
#include <utility>

using namespace std;
bool chess[302][302];

int main()
{
    int n;
    cin >> n;
    int dx[8] = {1, 1, 2, 2, -1, -1, -2, -2};
    int dy[8] = {2, -2, 1, -1, 2, -2, 1, -1};
    while (n--)
    {
        int l;
        int dist[302][302]{
            0,
        };
        cin >> l;
        pair<int, int> start;
        pair<int, int> final;
        cin >> start.first >> start.second;
        cin >> final.first >> final.second;
        queue<pair<int, int>> q;
        q.push(start);
        chess[start.first][start.second] = true;
        while (!q.empty())
        {
            pair<int, int> cur = q.front();
            q.pop();
            if (cur.first == final.first && cur.second == final.second)
            {
                cout << dist[final.first][final.second] << "\n";
                break;
            }
            for (int i = 0; i < 8; i++)
            {
                int nx = cur.first + dx[i];
                int ny = cur.second + dy[i];
                if (nx < 0 || ny < 0 || nx >= l || ny >= l)
                    continue;
                if (chess[nx][ny])
                    continue;

                dist[nx][ny] = dist[cur.first][cur.second] + 1;
                chess[nx][ny] = true;
                q.push({nx, ny});
            }
        }
        for (int i = 0; i < 302; i++)
            for (int j = 0; j < 302; j++)
                chess[i][j] = false;
    }
}