#include <iostream>
#include <queue>

using namespace std;

bool visited[100002];
int dist[100002];
int main()
{
    int m, n;
    cin >> m >> n;
    if (m == n)
    {
        cout << 0;
        return 0;
    }

    int dx[3] = {-1, 1, 2};
    queue<int> q;
    q.push(m);
    visited[m] = true;
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        for (int i = 0; i < 3; i++)
        {
            int nx;
            if (i == 2)
                nx = cur * dx[i];
            else
                nx = cur + dx[i];

            if (nx > 100000 || nx < 0)
                continue;
            if (visited[nx])
                continue;
            if (nx == n)
            {
                dist[nx] = dist[cur] + 1;
                cout << dist[nx];
                return 0;
            }
            q.push(nx);
            dist[nx] = dist[cur] + 1;
            visited[nx] = true;
        }
    }
}