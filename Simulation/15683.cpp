#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

int map[10][10];
int cp_map[10][10];
vector<tuple<int, int, int>> cctv;
bool isvisited[10][10];
int dir[10];
int n, m;
int ans = 2147000000;

void check_right(int x, int y)
{
    while (cp_map[x][y] != 6 && y < m)
    {
        if (cp_map[x][y] != 0)
        {
            y++;
            continue;
        }
        cp_map[x][y] = 7;
        y++;
    }
}

void check_left(int x, int y)
{
    while (cp_map[x][y] != 6 && y >= 0)
    {
        if (cp_map[x][y] != 0)
        {
            y--;
            continue;
        }
        cp_map[x][y] = 7;
        y--;
    }
}

void check_bottom(int x, int y)
{
    while (cp_map[x][y] != 6 && x < n)
    {
        if (cp_map[x][y] != 0)
        {
            x++;
            continue;
        }
        cp_map[x][y] = 7;
        x++;
    }
}

void check_top(int x, int y)
{
    while (cp_map[x][y] != 6 && x >= 0)
    {
        if (cp_map[x][y] != 0)
        {
            x--;
            continue;
        }
        cp_map[x][y] = 7;
        x--;
    }
}

void dfs(int cnt)
{
    if (cnt == cctv.size())
    {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
            {
                cp_map[i][j] = map[i][j];
            }
        for (int i = 0; i < cctv.size(); i++)
        {
            int x = get<0>(cctv[i]);
            int y = get<1>(cctv[i]);

            if (get<2>(cctv[i]) == 1)
            {
                if (dir[i] == 1)
                    check_right(x, y);
                else if (dir[i] == 2)
                    check_bottom(x, y);
                else if (dir[i] == 3)
                    check_left(x, y);
                else
                    check_top(x, y);
            }
            else if (get<2>(cctv[i]) == 2)
            {
                if (dir[i] % 2 == 1)
                {
                    check_bottom(x, y);
                    check_top(x, y);
                }
                else
                {
                    check_left(x, y);
                    check_right(x, y);
                }
            }
            else if (get<2>(cctv[i]) == 3)
            {
                if (dir[i] == 1)
                {
                    check_right(x, y);
                    check_bottom(x, y);
                }
                else if (dir[i] == 2)
                {
                    check_bottom(x, y);
                    check_left(x, y);
                }
                else if (dir[i] == 3)
                {
                    check_left(x, y);
                    check_top(x, y);
                }
                else
                {
                    check_top(x, y);
                    check_right(x, y);
                }
            }
            else if (get<2>(cctv[i]) == 4)
            {
                if (dir[i] == 1)
                {
                    check_right(x, y);
                    check_left(x, y);
                    check_bottom(x, y);
                }
                else if (dir[i] == 2)
                {
                    check_right(x, y);
                    check_left(x, y);
                    check_top(x, y);
                }
                else if (dir[i] == 3)
                {
                    check_bottom(x, y);
                    check_left(x, y);
                    check_top(x, y);
                }
                else
                {
                    check_bottom(x, y);
                    check_top(x, y);
                    check_right(x, y);
                }
            }
            else
            {
                check_bottom(x, y);
                check_left(x, y);
                check_right(x, y);
                check_top(x, y);
            }
        }
        int k = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
            {
                if (cp_map[i][j] == 0)
                    k++;
            }

        ans = min(ans, k);
        return;
    }

    for (int i = 0; i < 4; i++)
    {
        int x = get<0>(cctv[cnt]);
        int y = get<1>(cctv[cnt]);
        if (!isvisited[x][y])
        {
            isvisited[x][y] = true;
            dir[cnt] = i + 1;
            dfs(cnt + 1);
            isvisited[x][y] = false;
        }
    }
}

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    for (int i = 0; i < n; i++)
        for (int tmp, j = 0; j < m; j++)
        {

            cin >> tmp;
            map[i][j] = tmp;
            if (tmp > 0 && tmp < 6)
                cctv.push_back({i, j, tmp});
        }
    dfs(0);
    cout << ans;
}