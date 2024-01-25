#include <iostream>

using namespace std;

int map[51][51];
int n;
int m;
int r_x;
int r_y;
int r_dir;
int res;

bool check_back_up(int x, int y, int r_dir)
{

    if (r_dir == 0)
    {
        if (map[x + 1][y] == 1)
            return false;
        r_x = x + 1;
    }
    else if (r_dir == 1)
    {
        if (map[x][y - 1] == 1)
            return false;
        r_y = y - 1;
    }
    else if (r_dir == 2)
    {
        if (map[x - 1][y] == 1)
            return false;
        r_x = x - 1;
    }
    else if (r_dir == 3)
    {
        if (map[x][y + 1] == 1)
            return false;
        r_y = y + 1;
    }
    return true;
}

bool check_near_clean(int r_x, int r_y)
{
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    for (int i = 0; i < 4; i++)
    {
        int nx = r_x + dx[i];
        int ny = r_y + dy[i];

        if (nx < 0 || ny < 0 || nx >= n || ny >= m)
            continue;
        if (!map[nx][ny])
            return true;
    }
    return false;
}

void move_forward(int x, int y, int r_dir)
{
    if (r_dir == 0)
    {
        if (!map[x - 1][y])
            r_x = x - 1;
    }
    else if (r_dir == 1)
    {
        if (!map[x][y + 1])
            r_y = y + 1;
    }
    else if (r_dir == 2)
    {
        if (!map[x + 1][y])
            r_x = x + 1;
    }
    else if (r_dir == 3)
    {
        if (!map[x][y - 1])
            r_y = y - 1;
    }
}

int main()
{
    cin >> n >> m >> r_x >> r_y >> r_dir;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> map[i][j];

    while (true)
    {
        if (!map[r_x][r_y])
        {
            map[r_x][r_y] = 2;
            res++;
        }
        if (!check_near_clean(r_x, r_y))
        {
            if (!check_back_up(r_x, r_y, r_dir))
            {
                cout << res;
                break;
            }
            else
                continue;
        }
        else
        {
            r_dir = (r_dir + 3) % 4;
            move_forward(r_x, r_y, r_dir);
        }
    }
}