#include <bits/stdc++.h>

using namespace std;

int n, k;
queue<int> q;
int visited[100004];
int cnt[100004];

int main()
{
    cin >> n >> k;
    if (n == k)
    {
        cout << "0\n1";
        return 0;
    }
    visited[n]++;
    cnt[n]++;
    q.push(n);
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        for (int next : {cur + 1, cur - 1, cur * 2})
        {
            if (next >= 0 && next <= 100000)
            {
                if (!visited[next])
                {
                    visited[next] = visited[cur] + 1;
                    q.push(next);
                    cnt[next] += cnt[cur];
                }
                else if (visited[cur] + 1 == visited[next])
                {
                    cnt[next] += cnt[cur];
                }
            }
        }
    }
    cout << visited[k] - 1 << '\n'
         << cnt[k];
}