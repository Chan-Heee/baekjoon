#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

char map[32][32][32];
bool visited[32][32][32];
int dist[32][32][32];

int main()
{
    int l, r, c;
    string in;
    int dx[6] = {0, 0, 1, 0, -1, 0};
    int dy[6] = {0, 0, 0, 1, 0, -1};
    int dz[6] = {1, -1, 0, 0, 0, 0};
    while (1)
    {
        cin >> l >> r >> c;
        if (l == 0 && r == 0 && c == 0)
            break;
        queue<tuple<int, int, int>> q;
        tuple<int, int, int> fin;
        for (int i = 0; i < l; i++)
            for (int j = 0; j < r; j++)
            {
                cin >> in;
                for (int k = 0; k < c; k++)
                {
                    map[i][j][k] = in[k];
                    if (in[k] == 'S')
                    {
                        q.push({i, j, k});
                        visited[i][j][k] = true;
                    }
                    if (in[k] == 'E')
                        fin = {i, j, k};
                }
            }
        while (!q.empty())
        {
            tuple<int, int, int> cur = q.front();
            q.pop();
            for (int i = 0; i < 6; i++)
            {
                int nz = get<0>(cur) + dz[i];
                int nx = get<1>(cur) + dx[i];
                int ny = get<2>(cur) + dy[i];

                if (nx < 0 || ny < 0 || nz < 0 || nz >= l || nx >= r || ny >= c)
                    continue;
                if (visited[nz][nx][ny] || map[nz][nx][ny] == '#')
                    continue;

                dist[nz][nx][ny] = dist[get<0>(cur)][get<1>(cur)][get<2>(cur)] + 1;
                q.push({nz, nx, ny});
                visited[nz][nx][ny] = true;
            }
        }
        if (dist[get<0>(fin)][get<1>(fin)][get<2>(fin)] > 0)
            cout << "Escaped in " << dist[get<0>(fin)][get<1>(fin)][get<2>(fin)] << " minute(s)."
                 << "\n";
        else
            cout << "Trapped!"
                 << "\n";
        for (int i = 0; i < 32; i++)
            for (int j = 0; j < 32; j++)
                for (int k = 0; k < 32; k++)
                {
                    dist[i][j][k] = 0;
                    visited[i][j][k] = false;
                }
    }
}