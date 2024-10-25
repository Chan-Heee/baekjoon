#include <bits/stdc++.h>

using namespace std;
int n;
int board[14][14];
int visited[14][14];
int ans = 987654321;
vector<pair<int, int>> v;

void go(int cnt, int here_y, int here_x)
{
    if (cnt == 3)
    {
        int sum = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
            {
                if (visited[i][j])
                    sum += board[i][j];
            }
        ans = min(sum, ans);
        return;
    }
    for (int i = here_y; i < n; i++)
        for (int j = (here_y == i) ? here_x : 0; j < n; j++)
        {
            if (!visited[i][j] && i != n - 1 && i != 0 && j != 0 && j != n - 1)
            {
                if (visited[i + 1][j] || visited[i - 1][j] || visited[i][j + 1] || visited[i][j - 1])
                    continue;

                visited[i][j]++;
                visited[i + 1][j]++;
                visited[i][j + 1]++;
                visited[i - 1][j]++;
                visited[i][j - 1]++;
                go(cnt + 1, i, j);
                visited[i][j]--;
                visited[i + 1][j]--;
                visited[i][j + 1]--;
                visited[i - 1][j]--;
                visited[i][j - 1]--;
            }
        }
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> board[i][j];
    go(0, 0, 0);
    cout << ans;
}