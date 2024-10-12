#include <bits/stdc++.h>

using namespace std;

int n, k;
int visited[100004];
int path[100004];
queue<pair<int, int>> q;

int main()
{
    cin >> n >> k;
    visited[n]++;
    q.push({-1, n});
    while (!q.empty())
    {
        pair<int, int> cur = q.front();
        q.pop();
        path[cur.second] = cur.first;
        for (int next : {cur.second + 1, cur.second - 1, cur.second * 2})
        {
            if (next > 100000 || next < 0 || visited[next])
                continue;
            visited[next] = visited[cur.second] + 1;
            q.push({cur.second, next});
        }
    }
    int it = k;
    vector<int> v;
    while (it != -1)
    {
        v.push_back(path[it]);
        it = path[it];
    }
    cout << visited[k] - 1 << '\n';
    for (int i = v.size() - 2; i >= 0; i--)
        cout << v[i] << ' ';
    cout << k;
}