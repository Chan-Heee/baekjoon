#include <bits/stdc++.h>

using namespace std;

int m, n, k, X1, X2, Y1, Y2;
int a[104][104];
int visited[104][104];
vector<int> ret;
int cnt;
int f;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

int dfs(int y, int x)
{
    visited[y][x]++;
    int ret = 1;
    for (int i = 0; i < 4; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 0 || nx < 0 || nx >= m || ny >= n)
            continue;
        if (a[ny][nx] || visited[ny][nx])
            continue;

        ret += dfs(ny, nx);
    }
    return ret;
}

int main()
{
    cin >> n >> m >> k;
    for (int i = 0; i < k; i++)
    {
        cin >> X1 >> Y1 >> X2 >> Y2;
        for (int q = Y1; q < Y2; q++)
            for (int p = X1; p < X2; p++)
                a[q][p]++;
    }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            if (!visited[i][j] && !a[i][j])
                ret.push_back(dfs(i, j));
        }
    cout << ret.size() << '\n';
    sort(ret.begin(), ret.end());
    for (int i : ret)
        cout << i << " ";
}