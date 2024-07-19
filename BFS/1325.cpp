#include <bits/stdc++.h>

using namespace std;

int n, m, y, x, mx;
vector<int> p;
vector<int> h[10002];
int visited[10001];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> y >> x;
        h[x].push_back(y);
    }
    for (int i = 1; i <= n; i++)
    {
        fill(&visited[0], &visited[0] + 10001, 0);
        int cnt = 0;
        queue<int> q;
        visited[i] = 1;
        q.push(i);
        while (!q.empty())
        {
            int cur = q.front();
            q.pop();
            for (int neighbor : h[cur])
            {
                if (!visited[neighbor])
                {
                    visited[neighbor] = visited[cur] + 1;
                    cnt++;
                    q.push(neighbor);
                }
            }
        }
        if (mx == cnt)
            p.push_back(i);
        else if (mx < cnt)
        {
            mx = cnt;
            p.clear();
            p.push_back(i);
        }
    }
    for (int k : p)
        cout << k << ' ';
}