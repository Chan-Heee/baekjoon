#include <bits/stdc++.h>

using namespace std;
int n, m, h, tmp_y, tmp_x;
int ladders[34][14];
int ans = 4;

void dfs(int cnt, int goal)
{
    if (cnt == goal)
    {
        for (int i = 1; i <= n; i++)
        {
            int ny = 1;
            int nx = i;
            while (ny <= h)
            {
                if (ladders[ny][nx])
                    nx++;
                else if (nx > 1 && ladders[ny][nx - 1])
                    nx--;
                ny++;
            }
            if (i != nx)
                return;
        }
        ans = min(ans, goal);
        return;
    }

    for (int i = 1; i <= h; i++)
    {
        for (int j = 1; j < n; j++)
        {
            if (!ladders[i][j] && !ladders[i][j - 1] && !ladders[i][j + 1])
            {
                ladders[i][j] = 1;
                dfs(cnt + 1, goal);
                ladders[i][j] = 0;
            }
        }
    }
}
int main()
{
    cin >> n >> m >> h;
    for (int i = 0; i < m; i++)
    {
        cin >> tmp_y >> tmp_x;
        ladders[tmp_y][tmp_x] = 1;
    }
    for (int i = 0; i <= 3; i++)
    {
        dfs(0, i);
        if (ans != 4)
            break;
    }
    cout << (ans == 4 ? -1 : ans);
}
