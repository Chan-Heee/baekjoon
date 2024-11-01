#include <bits/stdc++.h>

using namespace std;
int n, m, tmpy, tmpx;
int board[104][104];
int visited[104];
int ans;

void dfs(int here)
{
    if (here != 1)
        ans++;
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i] && board[i][here])
        {
            visited[i]++;
            dfs(i);
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> tmpy >> tmpx;
        board[tmpy][tmpx] = 1;
        board[tmpx][tmpy] = 1;
    }
    visited[1]++;
    dfs(1);
    cout << ans;
}