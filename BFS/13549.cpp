#include <iostream>
#include <queue>

using namespace std;

bool visited[200004];
int dist[200004];

int main()
{
    int n, m;
    int dx[2] = {-1, 1};
    cin >> n >> m;
    if (n == m)
        cout << 0;
    else if (n > m)
        cout << n - m;
    else
    {
        visited[n] = true;
        queue<int> q1, q2;
        int cur1;
        int cur2;
        q1.push(n);
        while (!q1.empty())
        {
            cur1 = q1.front();
            q1.pop();
            q2.push(cur1);
            if (cur1 == m)
            {
                cout << dist[m];
                return 0;
            }
            while (!q2.empty())
            {
                cur2 = q2.front();
                q2.pop();
                int c = cur2 * 2;
                if (c > m * 2)
                    continue;
                if (visited[c])
                    continue;
                q2.push(c);
                q1.push(c);
                visited[c] = true;
                dist[c] = dist[cur2];

                if (cur2 == m)
                {
                    cout << dist[m];
                    return 0;
                }
            }
            for (int i = 0; i < 2; i++)
            {
                int nx = cur1 + dx[i];

                if (nx < 0 || nx > 200000)
                    continue;
                if (visited[nx])
                    continue;

                q1.push(nx);
                visited[nx] = true;
                dist[nx] = dist[cur1] + 1;
            }
        }
    }
}